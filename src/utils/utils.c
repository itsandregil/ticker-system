#include "utils/utils.h"
#include "utils/validation.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *read_string_input(char *prompt, validate_fn validate) {
  char *s = malloc(MAX_BUFFER_SIZE + 1);
  if (s == NULL) {
    return NULL;
  }
  while (1) {
    printf("%s: ", prompt);
    if (!fgets(s, MAX_BUFFER_SIZE, stdin)) {
      free(s);
      return NULL;
    }
    s[strcspn(s, "\n")] = '\0';
    char *err = validate ? validate(s) : NULL;
    if (!err) {
      return s;
    }
    printf("%s\n\n", err);
  }
}

int generate_random_id() {
  srand(time(NULL));
  return rand();
}

int is_numeric(const char *s) {
  for (; *s; s++) {
    if (!isdigit((unsigned char)*s)) {
      return 0;
    }
  }
  return 1;
}

int has_length_between(const char *s, size_t min, size_t max) {
  size_t len = strlen(s);
  return len >= min && len <= max;
}

int is_not_empty(const char *s) { return s && *s; }
