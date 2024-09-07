#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid, status;
  pid = fork();
  if (pid == 0) {
    char *argv[] = {"echo", "THIS", "IS", "ECHO", 0};
    int ret = execv("/usr/bin/echo", argv);
    // int ret = execv("echo", argv);  error
    printf("exec failed! result : %d, reason : %s\n", ret, strerror(errno));
    exit(1);
  } else {
    printf("parent waiting\n");
    wait(&status);
    printf("this child exited with status %d\n", status);
  }
  exit(0);
}
