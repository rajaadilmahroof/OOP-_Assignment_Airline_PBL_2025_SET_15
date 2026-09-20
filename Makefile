CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SOURCES = main.cpp src/Flight.cpp src/Passenger.cpp src/Ticket.cpp src/Airline.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -Iinclude -o airline

run: all
	./airline

clean:
	rm -f airline airline.exe
