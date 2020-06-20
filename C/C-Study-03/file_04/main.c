#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

void read_all_files(char *path,char *depth) {
  printf("<%s>\n", path);

  DIR *root = opendir(path);
  if (root == NULL) {
    perror("E");
    return;
  }

  struct dirent *item = NULL;
  while ((item = readdir(root)) != NULL) {
    /* Dont't show unless dirctory file */
    if ((strcmp(item->d_name, ".") == 0) || (strcmp(item->d_name, "..") == 0)) continue;

    printf("%s%s ", depth, item->d_name);
    switch (item->d_type) {
    case DT_DIR:
      printf("[dir]");
      break;
    case DT_REG:
      printf("[reg]");
      break;
    default:
      printf("[unknown]");
      break;
    }

    if (item->d_type == DT_DIR) {
      /* folder */
      char *next_folder = malloc(strlen(path) + strlen(item->d_name) + 8);
      sprintf(next_folder, "%s%s/", path, item->d_name);

      /* depth */
      char *depth_next = malloc(strlen(depth) + strlen("  ") + 8);
      sprintf(depth_next, "%s%s", depth, "  ");

      printf("\n%s",depth_next);

      /* To next loop */
      read_all_files(next_folder, depth_next);

      free(depth_next);
      free(next_folder);
      continue;
    }

    putchar('\n');
  }

  closedir(root);
}

int main(int argc, char *argv[]) {
  read_all_files(argv[1], " ");
  return EXIT_SUCCESS;
}
