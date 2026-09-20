#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <string>
class Passenger {
protected: int id; std::string name;
public:
    Passenger(int,const std::string&); virtual ~Passenger()=default;
    virtual void display() const=0; virtual std::string classType() const=0;
    int getId() const; const std::string& getName() const;
    bool operator==(const Passenger&) const;
    friend std::ostream& operator<<(std::ostream&,const Passenger&);
};
class EconomyPassenger:public Passenger{public:EconomyPassenger(int,const std::string&);void display()const override;std::string classType()const override;};
class BusinessPassenger:public Passenger{public:BusinessPassenger(int,const std::string&);void display()const override;std::string classType()const override;};
class FirstClassPassenger:public Passenger{public:FirstClassPassenger(int,const std::string&);void display()const override;std::string classType()const override;};
#endif
