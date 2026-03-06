#ifndef UTILS_H
#define UTILS_H

#include "validation.h"
#include <stddef.h>
#define MAX_BUFFER_SIZE 500

char *read_string_input(char *prompt, validate_fn validate);
int generate_random_id();
int is_not_empty(const char *s);
int is_numeric(const char *s);
int has_length_between(const char *s, size_t min, size_t max);

#endif
