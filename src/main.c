#include "ticket/ticket.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ticket_t *ticket = new_ticket();
  if (ticket == NULL) {
    printf("Creation process failed. Try Again.\n");
    return 1;
  }
  save_ticket(ticket);
  printf("Ticket saved successfully.\n");
  printf("Ticket ID: %d\n", ticket->id);
  free_ticket(ticket);
  return 0;
}
