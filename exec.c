#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  // 这种方式会省略掉数组中第一个参数。
  char *argv[] = {"echo", "this", "is", "echo", 0};
  int ret = execv("/usr/bin/echo", argv);
  printf("exec failed! result : %d, reason : %s\n", ret, strerror(errno));
  exit(0);
}
