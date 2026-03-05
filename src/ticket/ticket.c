#include "ticket/ticket.h"
#include "utils/utils.h"
#include <stdlib.h>

ticket_t new_ticket() {
  char *id = read_string_input("Ingresa tu ID", is_valid_id);
  char *email = read_string_input("Ingresa tu email", is_valid_email);
  char *description = read_string_input("Describe tu reclamo", is_not_empty);
  ticket_t ticket = {.id = id, .email = email, .description = description};
  return ticket;
}

void free_ticket(ticket_t *ticket) {
  if (ticket == NULL) {
    return;
  }
  free(ticket);
}
