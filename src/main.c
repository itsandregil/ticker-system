#include "ticket/ticket.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ticket_t *ticket = new_ticket();
  save_ticket(ticket);
  return 0;
}
