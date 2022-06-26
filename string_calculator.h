#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>


unsigned int digit_to_decimal(char digit);


char decimal_to_digit(unsigned int decimal);


std::string trim_leading_zeros(std::string num);


std::string add(std::string lhs, std::string rhs);


std::string multiply(std::string lhs, std::string rhs);

#endif  
