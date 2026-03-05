#ifndef TICKET_H
#define TICKET_H

typedef struct Ticket {
    char *id;
    char *email;
    char *description;
} ticket_t;

ticket_t *new_ticket();
char *generate_ticket_filename();
void save_ticket(ticket_t *ticket);
void write_ticket(char *filename, ticket_t *ticket);
void free_ticket(ticket_t *ticket);

#endif
