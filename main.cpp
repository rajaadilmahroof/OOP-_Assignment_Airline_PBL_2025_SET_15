#include <iostream>
#include "include/Airline.h"

int main() {
    Airline airline;
    airline.addFlight(new DomesticFlight("SK101", "Muzaffarabad", "Islamabad", 100));
    airline.addFlight(new InternationalFlight("SK202", "Islamabad", "Dubai", 180));
    airline.addFlight(new CharterFlight("SK303", "Lahore", "Karachi", 60));

    airline.addPassenger(new EconomyPassenger(1, "Ali"));
    airline.addPassenger(new BusinessPassenger(2, "Ahmed"));
    airline.addPassenger(new FirstClassPassenger(3, "Usman"));

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n========== SKYLINK AIRWAYS ==========\n"
                  << "1. View Flights\n2. Search Flight\n3. View Passengers\n"
                  << "4. Book Ticket\n5. Cancel Ticket\n6. View Tickets\n"
                  << "7. Reports\n8. Save Data\n0. Exit\nEnter choice: ";
        std::cin >> choice;
        try {
            switch (choice) {
                case 1: airline.viewFlights(); break;
                case 2: airline.searchFlight(); break;
                case 3: airline.viewPassengers(); break;
                case 4: airline.bookTicket(); break;
                case 5: airline.cancelTicket(); break;
                case 6: airline.viewTickets(); break;
                case 7: airline.reports(); break;
                case 8: airline.saveData("data/sample_data.txt"); break;
                case 0: std::cout << "Thank you for using SkyLink Airways.\n"; break;
                default: std::cout << "Invalid choice.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
    return 0;
}
