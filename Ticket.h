#ifndef TICKET_H
#define TICKET_H
#include "Flight.h"
#include "Passenger.h"
class Ticket {
    int ticketId; Flight* flight; Passenger* passenger;
public:
    Ticket(int,Flight*,Passenger*); int getTicketId()const; Flight* getFlight()const; Passenger* getPassenger()const; void display()const;
};
#endif
