#include "ticket/ticket.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ticket_t *ticket = new_ticket();
  if (ticket == NULL) {
    return 1;
  }
  save_ticket(ticket);
  return 0;
}
