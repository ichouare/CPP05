#ifndef BEREAUCRAT_H
#define BEREAUCRAT_H
#include <iostream>
#include <exception>

class Bureaucrat
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
        Bureaucrat(const Bureaucrat& original);
        Bureaucrat& operator=(const Bureaucrat& original);
        class GradeTooHighException : public std::exception 
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};


std::ostream& operator<<(std::ostream& flux, const Bureaucrat obj);
#endif