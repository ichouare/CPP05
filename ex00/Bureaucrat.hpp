#ifndef BEREAUCRAT_H
#define BEREAUCRAT_H
#include "./GradeTooHighException.hpp"
#include "./GradeTooLowException.hpp"
#include <iostream>


class Bureaucrat: public GradeTooHighException , public  GradeTooLowException
{
    private :
        const std::string m_name;
        int m_grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string m_name, int m_grade);
        ~Bureaucrat();
        std::string  getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

};


std::ostream& operator<<(std::ostream& flux, const Bureaucrat obj);
#endif