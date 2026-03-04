#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Implement more validation for input strings

/*
 * A function that reads a string from the terminal using
 * a custom prompt.
 */
char *read_string_input(char *prompt){
  char *s = malloc((MAX_BUFFER_SIZE + 1) * sizeof(char));
  if (s == NULL) {
    return NULL;
  }
  printf("%s\n", prompt);
  fgets(s, MAX_BUFFER_SIZE, stdin);
  if (strlen(s) == 0) {
    free(s);
    return NULL;
  }
  return s;
}
