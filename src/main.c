#include "ticket/ticket.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ticket_t *ticket = new_ticket();
  if (ticket == NULL) {
    printf("Creation process failed. Try Again.");
    return 1;
  }
  save_ticket(ticket);
  printf("Ticket saved successfully.\n");
  return 0;
}
