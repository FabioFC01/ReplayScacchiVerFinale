#include "Exception.h"

string const Exception::what() const {
	return description_;
}
