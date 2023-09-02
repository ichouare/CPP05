#ifndef FORM_H
#define FORM_H


#include <iostream>
#include <string>
#include <exception>
#include "./Bureaucrat.hpp"
class Form {
    public:
    Form();
    Form(std::string m_name, int m_grade_signed, int m_grade_execute);
    Form(const Form& original);
    Form& operator=(const Form& original);
    ~Form();
    std::string getName() const;
    bool getSignal()const;
    int getSignalSign() const;
    int getSignalExecute() const;
    void beSigne(Bureaucrat obj);

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
    private:
        const std::string m_name;
        bool m_signal;
        const int m_grade_sign;
        const int m_grade_execute;

};


std::ostream & operator<<(std::ostream &flux, const Form obj);
#endif