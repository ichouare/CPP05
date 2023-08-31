#include "./Bureaucrat.hpp"


Bureaucrat::Bureaucrat():m_name("undefine"),m_grade(0)
{

}

Bureaucrat::Bureaucrat(std::string m_name, int m_grade):m_name(m_name),m_grade(m_grade)
{
    if(m_grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else if (m_grade > 150)
        throw Bureaucrat::GradeTooLowException();

}


Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const 
{
    return m_name;
}


int Bureaucrat::getGrade() const 
{
    return m_grade;
}

void Bureaucrat::incrementGrade()
{
    m_grade++;
     if(m_grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else if (m_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
    m_grade--;
     if(m_grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else if (m_grade > 150)
             throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& flux, const Bureaucrat obj )
{
   
   flux << obj.getName();
    flux << " , bureaucrat grade ";
   flux << obj.getGrade();
   return flux;

    
}