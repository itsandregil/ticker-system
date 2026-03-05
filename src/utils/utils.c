#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *read_string_input(char *prompt, int (*cb)(char *)) {
  char *s = malloc((MAX_BUFFER_SIZE + 1) * sizeof(char));
  if (s == NULL) {
    return NULL;
  }
  printf("%s:\n", prompt);
  fgets(s, MAX_BUFFER_SIZE, stdin);
  if (cb(s) != 0) {
    free(s);
    exit(1);
  }
  return s;
}

int is_not_empty(char *string) {
  if (strlen(string) - 1 > 0) {
    return 0;
  }
  printf("Field cannot be empty!\n");
  return 1;
}

int is_valid_email(char *string) {
  if (is_not_empty(string) == 0 && strchr(string, '@') != NULL) {
    return 0;
  }
  printf("Invalid email format\n");
  return 1;
}

int is_valid_id(char *string) {
  size_t len = strlen(string) - 1;
  if (is_not_empty(string) == 0 && len >= 8 && len <= 10) {
    return 0;
  }
  printf("Not a valid ID: must be between 8 and 10 characters\n");
  return 1;
}

int generate_random_id() {
  srand(time(NULL));
  return rand();
}
