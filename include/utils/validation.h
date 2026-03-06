#ifndef VALIDATION_H
#define VALIDATION_H

typedef char *(*validate_fn)(const char *);

char *is_valid_email(const char *email);
char *is_valid_id(const char *id);
char *is_valid_desc(const char *desc);

#endif
