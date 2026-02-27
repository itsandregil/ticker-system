#include <stdio.h>

int main() {
  char id[50];

  printf("Hello world\n");
  printf("Enter your ID: ");
  fgets(id, 50, stdin);
  printf("You enter: %s", id);
  return 0;
}
