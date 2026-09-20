#include "../include/Airline.h"
#include <algorithm>
#include <fstream>
#include <iostream>
Passenger* Airline::findPassenger(int id)const{for(auto p:passengers)if(p->getId()==id)return p;return nullptr;}
Flight* Airline::findFlight(const std::string& n)const{for(auto f:flights)if(f->getFlightNumber()==n)return f;return nullptr;}
Airline::~Airline(){for(auto t:tickets)delete t;for(auto f:flights)delete f;for(auto p:passengers)delete p;}
void Airline::addFlight(Flight* f){flights.push_back(f);}
void Airline::addPassenger(Passenger* p){passengers.push_back(p);}
void Airline::viewFlights()const{std::cout<<"\n===== FLIGHTS =====\n";for(auto f:flights)f->display();}
void Airline::viewPassengers()const{std::cout<<"\n===== PASSENGERS =====\n";for(auto p:passengers)p->display();}
void Airline::viewTickets()const{std::cout<<"\n===== TICKETS =====\n";if(tickets.empty()){std::cout<<"No tickets found.\n";return;}for(auto t:tickets)t->display();}
void Airline::searchFlight()const{std::string n;std::cout<<"Enter flight number: ";std::cin>>n;auto f=findFlight(n);if(!f)throw BookingException("Flight not found.");f->display();}
void Airline::bookTicket(){int tid,pid;std::string fn;std::cout<<"Enter ticket ID: ";std::cin>>tid;std::cout<<"Enter passenger ID: ";std::cin>>pid;std::cout<<"Enter flight number: ";std::cin>>fn;if(std::any_of(tickets.begin(),tickets.end(),[tid](auto t){return t->getTicketId()==tid;}))throw BookingException("Ticket ID already exists.");auto p=findPassenger(pid);auto f=findFlight(fn);if(!p)throw BookingException("Passenger not found.");if(!f)throw BookingException("Flight not found.");tickets.push_back(new Ticket(tid,f,p));std::cout<<"Ticket booked successfully.\n";}
void Airline::cancelTicket(){int tid;std::cout<<"Enter ticket ID to cancel: ";std::cin>>tid;auto it=std::find_if(tickets.begin(),tickets.end(),[tid](auto t){return t->getTicketId()==tid;});if(it==tickets.end())throw BookingException("Ticket not found.");delete *it;tickets.erase(it);std::cout<<"Ticket cancelled successfully.\n";}
void Airline::reports()const{std::cout<<"\n========== REPORT ==========\n";showCount(flights);showCount(passengers);showCount(tickets);std::cout<<"============================\n";}
void Airline::saveData(const std::string& fileName)const{std::ofstream file(fileName);if(!file)throw BookingException("Could not open data file.");file<<"SKYLINK AIRWAYS SAMPLE DATA\n\nFlights: "<<flights.size()<<"\n";for(auto f:flights)file<<f->getFlightNumber()<<" | "<<f->type()<<" | Capacity: "<<f->getCapacity()<<"\n";file<<"\nPassengers: "<<passengers.size()<<"\n";for(auto p:passengers)file<<p->getId()<<" | "<<p->getName()<<" | "<<p->classType()<<"\n";file<<"\nTickets: "<<tickets.size()<<"\n";for(auto t:tickets)file<<t->getTicketId()<<" | Flight: "<<t->getFlight()->getFlightNumber()<<" | Passenger: "<<t->getPassenger()->getId()<<"\n";std::cout<<"Data saved to "<<fileName<<"\n";}
