#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#define MAX_BUFFER_SIZE 255

char *read_string_input(char *prompt, int (*cb)(char *));
int validate_email(char *string);
int validate_id(char *string);
int validate_is_not_empty(char *string);

#endif
