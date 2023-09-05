#ifndef FORM_H
#define FORM_H


#include <iostream>
#include <string>
#include <exception>
#include "./Bureaucrat.hpp"

class Bureaucrat;
class AForm {
    public:
        AForm();
        AForm(std::string m_name, int m_grade_signed, int m_grade_execute);
        AForm(const AForm& original);
        AForm& operator=(const AForm& original);
        virtual ~AForm();
        std::string getName() const;
        bool getSigned()const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(Bureaucrat obj);
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class NotSignedException : public std::exception
            {
                public:
                    const char *what() const throw();
            };
    private:
        const  std::string m_name;
        bool    m_signed;
        const  int m_grade_signed;
        const  int m_grade_execute;

};


std::ostream & operator<<(std::ostream & flux, const AForm& obj);
#endif