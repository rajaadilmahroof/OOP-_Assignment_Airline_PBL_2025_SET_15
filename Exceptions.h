#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>
class BookingException : public std::runtime_error {
public:
    explicit BookingException(const std::string& message) : std::runtime_error(message) {}
};
#endif
