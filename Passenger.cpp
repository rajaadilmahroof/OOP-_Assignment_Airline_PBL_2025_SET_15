#include "../include/Passenger.h"
Passenger::Passenger(int i,const std::string& n):id(i),name(n){}
int Passenger::getId()const{return id;}
const std::string& Passenger::getName()const{return name;}
bool Passenger::operator==(const Passenger& o)const{return id==o.id;}
std::ostream& operator<<(std::ostream& out,const Passenger& p){out<<"ID: "<<p.id<<" | Name: "<<p.name<<" | Class: "<<p.classType();return out;}
EconomyPassenger::EconomyPassenger(int i,const std::string& n):Passenger(i,n){}
void EconomyPassenger::display()const{std::cout<<*this<<'\n';}
std::string EconomyPassenger::classType()const{return "Economy";}
BusinessPassenger::BusinessPassenger(int i,const std::string& n):Passenger(i,n){}
void BusinessPassenger::display()const{std::cout<<*this<<'\n';}
std::string BusinessPassenger::classType()const{return "Business";}
FirstClassPassenger::FirstClassPassenger(int i,const std::string& n):Passenger(i,n){}
void FirstClassPassenger::display()const{std::cout<<*this<<'\n';}
std::string FirstClassPassenger::classType()const{return "First Class";}
