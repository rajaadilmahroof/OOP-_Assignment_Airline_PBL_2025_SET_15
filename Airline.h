#ifndef AIRLINE_H
#define AIRLINE_H
#include <string>
#include <vector>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Exceptions.h"
class Airline {
    std::vector<Flight*> flights; std::vector<Passenger*> passengers; std::vector<Ticket*> tickets;
    Passenger* findPassenger(int)const; Flight* findFlight(const std::string&)const;
public:
    ~Airline();
    void addFlight(Flight*); void addPassenger(Passenger*);
    void viewFlights()const; void viewPassengers()const; void viewTickets()const; void searchFlight()const;
    void bookTicket(); void cancelTicket(); void reports()const; void saveData(const std::string&)const;
};
template<typename T> void showCount(const std::vector<T>& items){std::cout<<"Total items: "<<items.size()<<'\n';}
#endif
