#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid;

  pid = fork();

  if (pid == 0) {
    close(1);
    open("output.txt", O_WRONLY | O_CREAT);

    char *argv[] = {"echo", "this", "is", "redirected", "echo", 0};
    int ret = execv("/usr/bin/echo", argv);
    printf("exec failed! result : %d, reason : %s\n", ret, strerror(errno));
    exit(1);
  } else {
    wait((int *)0);
  }
  exit(0);
}
