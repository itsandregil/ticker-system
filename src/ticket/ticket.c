#include "ticket/ticket.h"
#include "utils/utils.h"
#include "utils/validation.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

ticket_t *new_ticket() {
  ticket_t *ticket = malloc(sizeof(ticket_t));
  if (ticket == NULL) {
    return NULL;
  }
  ticket->user_id = read_string_input("Enter your ID number", is_valid_id);
  ticket->email = read_string_input("Enter your email address", is_valid_email);
  ticket->description = read_string_input("Describe your claim", is_valid_desc);
  if (!ticket->user_id || !ticket->email || !ticket->description) {
    free_ticket(ticket);
    return NULL;
  }
  ticket->id = generate_random_id();
  return ticket;
}

void free_ticket(ticket_t *ticket) {
  if (ticket == NULL) {
    return;
  }
  free(ticket->user_id);
  free(ticket->email);
  free(ticket->description);
  free(ticket);
}

char *generate_filename() {
  char *filename = malloc((MAX_BUFFER_SIZE + 1) * sizeof(char));
  if (filename == NULL) {
    return NULL;
  }
  sprintf(filename, "assets/ticket_%d.txt", generate_random_id());
  return filename;
}

void save_ticket(ticket_t *ticket) {
  char *filename = generate_filename();
  if (filename == NULL) {
    return;
  }
  struct stat st = {0};
  if (stat("assets", &st) == -1) {
    mkdir("assets", 0700);
  }
  write_ticket(filename, ticket);
  free_ticket(ticket);
}

void write_ticket(char *filename, ticket_t *ticket) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    free(filename);
    return;
  }
  fprintf(file, "Ticket ID: %d\n", ticket->id);
  fprintf(file, "User ID: %s\n", ticket->user_id);
  fprintf(file, "Email: %s\n", ticket->email);
  fprintf(file, "Claim description: %s\n", ticket->description);
  fclose(file);
  free(filename);
}
