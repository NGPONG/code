#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
  struct passwd *user;
  user = getpwnam("root");
  printf("name:%s\n", user->pw_name);
  printf("uid:%d\n", user->pw_uid);
  printf("home:%s\n", user->pw_dir);

  return -1;
}
