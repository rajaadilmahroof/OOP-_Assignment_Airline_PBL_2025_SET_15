#include "../include/Ticket.h"
#include <iostream>
Ticket::Ticket(int i,Flight* f,Passenger* p):ticketId(i),flight(f),passenger(p){}
int Ticket::getTicketId()const{return ticketId;}
Flight* Ticket::getFlight()const{return flight;}
Passenger* Ticket::getPassenger()const{return passenger;}
void Ticket::display()const{std::cout<<"Ticket ID: "<<ticketId<<" | Flight: "<<flight->getFlightNumber()<<" | Passenger: "<<passenger->getName()<<'\n';}
