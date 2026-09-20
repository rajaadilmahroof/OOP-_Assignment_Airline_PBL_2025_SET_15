# UML Diagram

```text
                    <<abstract>>
                       Flight
                         |
        +----------------+----------------+
        |                |                |
 DomesticFlight  InternationalFlight  CharterFlight


                    <<abstract>>
                      Passenger
                         |
        +----------------+----------------+
        |                |                |
 EconomyPassenger BusinessPassenger FirstClassPassenger


                       Airline
                  /       |       \
             Flights Passengers Tickets
                                  /   \
                               Flight Passenger
```
