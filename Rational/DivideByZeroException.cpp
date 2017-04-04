#include "DivideByZeroException.h"

DivideByZeroException::DivideByZeroException() : runtime_error("Attempted to divide by zero")
{}

DivideByZeroException::DivideByZeroException(const char *message) :runtime_error(message)
{}

