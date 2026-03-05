#include "ticket/ticket.h"
#include <stdio.h>

int main() {
  ticket_t ticket = new_ticket();
  free_ticket(&ticket);
  return 0;
}
