#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/* This function writes a message directly to standard error,
   without using the stderr stream.  This is async-signal safe.
   Returns 0 if success, errno error code if an error occurs.
   errno is kept unchanged. */
static int write_stderr(const char *msg)
{
    const char *end = msg;
    const int   saved_errno = errno;
    int         retval = 0;
    ssize_t     n;

    /* If msg is non-NULL, find the string-terminating '\0'. */
    if (msg)
        while (*end)
            end++;

    /* Write the message to standard error. */
    while (msg < end) {
        n = write(STDERR_FILENO, msg, (size_t)(end - msg));
        if (n > 0) {
            msg += n;
        } else
        if (n != 0) {
            /* Bug, should not occur */
            retval = EIO;
            break;
        } else
        if (errno != EINTR) {
            retval = errno;
            break;
        }
    }

    /* Paranoid check that exactly the message was written */
    if (!retval)
        if (msg != end)
            retval = EIO;

    errno = saved_errno;
    return retval;
}

static volatile sig_atomic_t  done = 0;
pthread_t                     main_thread;
pthread_t                     other_thread;

static void signal_handler(int signum)
{
    const pthread_t  id = pthread_self();
    const char *thread = (id == main_thread) ? "Main thread" :
                         (id == other_thread) ? "Other thread" : "Unknown thread";
    const char *event = (signum == SIGHUP) ? "HUP" :
                        (signum == SIGUSR1) ? "USR1" :
                        (signum == SIGINT) ? "INT" :
                        (signum == SIGTERM) ? "TERM" : "Unknown signal";

    if (signum == SIGTERM || signum == SIGINT)
        done = 1;

    write_stderr(thread);
    write_stderr(": ");
    write_stderr(event);
    write_stderr(".\n");
}

static int install_handler(int signum)
{
    struct sigaction  act;
    memset(&act, 0, sizeof act);
    sigemptyset(&act.sa_mask);
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    if (sigaction(signum, &act, NULL) == -1)
        return -1;
    return 0;
}

void *other(void *unused __attribute__((unused)))
{
    sigset_t  mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);
    sigaddset(&mask, SIGHUP);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);

    while (!done)
        sleep(1);

    return NULL;
}

int main(void)
{
    pthread_attr_t  attrs;
    sigset_t        mask;
    int             result;

    main_thread = pthread_self();
    other_thread = pthread_self(); /* Just to initialize it to a sane value */

    /* Install HUP, USR1, INT, and TERM signal handlers. */
    if (install_handler(SIGHUP) ||
        install_handler(SIGUSR1) ||
        install_handler(SIGINT) ||
        install_handler(SIGTERM)) {
        fprintf(stderr, "Cannot install signal handlers: %s.\n", strerror(errno));
        return EXIT_FAILURE;
    }

    /* Create the other thread. */
    pthread_attr_init(&attrs);
    pthread_attr_setstacksize(&attrs, 2*PTHREAD_STACK_MIN);
    result = pthread_create(&other_thread, &attrs, other, NULL);
    pthread_attr_destroy(&attrs);
    if (result) {
        fprintf(stderr, "Cannot create a thread: %s.\n", strerror(result));
        return EXIT_FAILURE;
    }

    /* This thread blocks SIGUSR1. */
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);

    /* Ready to handle signals. */
    printf("Send a HUP, USR1, or TERM signal to process %d.\n", (int)getpid());
    fflush(stdout);

    while (!done)
        sleep(1);

    pthread_join(other_thread, NULL);

    return EXIT_SUCCESS;
}
