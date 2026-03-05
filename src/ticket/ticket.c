#include "ticket/ticket.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

ticket_t *new_ticket() {
  ticket_t *ticket = malloc(sizeof(ticket_t));
  if (ticket == NULL) {
    return NULL;
  }

  char *user_id = read_string_input("Ingresa tu ID", is_valid_id);
  char *email = read_string_input("Ingresa tu email", is_valid_email);
  char *description = read_string_input("Describe tu reclamo", is_not_empty);

  ticket->id = generate_random_id();
  ticket->user_id = user_id;
  ticket->email = email;
  ticket->description = description;
  return ticket;
}

void free_ticket(ticket_t *ticket) {
  if (ticket == NULL) {
    return;
  }
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
  fprintf(file, "Radicado: %d\n", ticket->id);
  fprintf(file, "Identificación: %s", ticket->user_id);
  fprintf(file, "Correo: %s", ticket->email);
  fprintf(file, "Descripcion Reclamo: %s", ticket->description);
  fclose(file);
  free(filename);
}
