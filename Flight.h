#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
class Flight {
protected:
    std::string flightNumber, origin, destination;
    int capacity;
public:
    Flight(const std::string&, const std::string&, const std::string&, int);
    virtual ~Flight() = default;
    virtual void display() const = 0;
    virtual std::string type() const = 0;
    const std::string& getFlightNumber() const;
    int getCapacity() const;
    bool operator==(const Flight&) const;
    friend std::ostream& operator<<(std::ostream&, const Flight&);
};
class DomesticFlight : public Flight {
public:
    DomesticFlight(const std::string&, const std::string&, const std::string&, int);
    void display() const override; std::string type() const override;
};
class InternationalFlight : public Flight {
public:
    InternationalFlight(const std::string&, const std::string&, const std::string&, int);
    void display() const override; std::string type() const override;
};
class CharterFlight : public Flight {
public:
    CharterFlight(const std::string&, const std::string&, const std::string&, int);
    void display() const override; std::string type() const override;
};
#endif
