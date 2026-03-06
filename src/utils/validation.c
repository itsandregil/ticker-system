#include "utils/validation.h"
#include "utils/utils.h"
#include <stdio.h>
#include <string.h>

char *is_valid_email(const char *string) {
  if (!is_not_empty(string)) {
    return "Email cannot be empty!";
  }
  if (strchr(string, '@') == NULL) {
    return "Invalid email format: missing @";
  }
  return NULL;
}

char *is_valid_id(const char *string) {
  if (!is_not_empty(string)) {
    return "ID cannot be empty!";
  }
  if (!is_numeric(string)) {
    return "Invalid ID format: must be numeric";
  }
  if (!has_length_between(string, 8, 10)) {
    return "Invalid ID format: must be between 8 and 10 characters";
  }
  return NULL;
}

char *is_valid_desc(const char *desc) {
  if (!is_not_empty(desc)) {
    return "Description cannot be empty!";
  }
  return NULL;
}
