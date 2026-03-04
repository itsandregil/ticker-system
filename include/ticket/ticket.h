#ifndef TICKET_H
#define TICKET_H

typedef enum Complaint {
    ENSURANCE = 1,
    PUBLIC_SERVICES,
    ADMINISTRATIVE
} complaint_t;

typedef struct Ticket {
    int id_number;
    char *email;
    complaint_t complaint_type;
} ticket_t;


complaint_t get_complaint_from_input(int value);
ticket_t create_new_ticket(int id_number, char *email, complaint_t complaint_type);
void save_ticket(ticket_t *ticket);
void free_ticket(ticket_t *ticket);
void print_ticket(ticket_t *ticket);

#endif
