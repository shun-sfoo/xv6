#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd = open("output.txt", O_WRONLY | O_CREAT);
  write(fd, "ooo\n", 4);
  exit(0);
}
