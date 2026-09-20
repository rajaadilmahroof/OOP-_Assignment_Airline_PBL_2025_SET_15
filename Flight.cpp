#include "../include/Flight.h"
Flight::Flight(const std::string& n,const std::string& f,const std::string& t,int c):flightNumber(n),origin(f),destination(t),capacity(c){}
const std::string& Flight::getFlightNumber() const{return flightNumber;}
int Flight::getCapacity() const{return capacity;}
bool Flight::operator==(const Flight& o) const{return flightNumber==o.flightNumber;}
std::ostream& operator<<(std::ostream& out,const Flight& f){out<<f.flightNumber<<" | "<<f.origin<<" -> "<<f.destination<<" | "<<f.type()<<" | Capacity: "<<f.capacity;return out;}
DomesticFlight::DomesticFlight(const std::string& n,const std::string& f,const std::string& t,int c):Flight(n,f,t,c){}
void DomesticFlight::display() const{std::cout<<*this<<'\n';}
std::string DomesticFlight::type() const{return "Domestic";}
InternationalFlight::InternationalFlight(const std::string& n,const std::string& f,const std::string& t,int c):Flight(n,f,t,c){}
void InternationalFlight::display() const{std::cout<<*this<<'\n';}
std::string InternationalFlight::type() const{return "International";}
CharterFlight::CharterFlight(const std::string& n,const std::string& f,const std::string& t,int c):Flight(n,f,t,c){}
void CharterFlight::display() const{std::cout<<*this<<'\n';}
std::string CharterFlight::type() const{return "Charter";}
