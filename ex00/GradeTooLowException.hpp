#ifndef GRADEHIGH_H
#define GRADEHIGH_H

#include <iostream>
#include <exception>
#include <string>


class GradeTooLowException : public std::exception
{
    private:
        std::string m_error;
    public:
    GradeTooLowException();

};

#endif