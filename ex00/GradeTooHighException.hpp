#ifndef GRADELower_H
#define GRADELower_H


#include <iostream>
#include <exception>
#include <string>

class GradeTooHighException : public std::exception
{
    private:
        std::string m_error;
    public:
    GradeTooHighException();

};

#endif