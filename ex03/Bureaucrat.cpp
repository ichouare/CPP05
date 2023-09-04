#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat():m_name("undefine"),m_grade(0)
{

}

Bureaucrat::Bureaucrat(std::string m_name, int m_grade):m_name(m_name),m_grade(m_grade)
{
    if(m_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (m_grade > 150)
        throw Bureaucrat::GradeTooLowException();

}


Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& original):m_name(original.getName())
{
    *(this) = original;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original)
{
    if(this == &original)
        return (*this);
    this->m_grade = original.m_grade;
    return (*this);
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
     if(m_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (m_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
    m_grade--;
    if(m_grade < 1)
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException: out of range";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: out of range";
}


void Bureaucrat::signForm(const AForm& obj)
{
    if(obj.getSigned() == true)
        std::cout << *this << " signed " << obj << std::endl;
    else
        std::cout << *this << " couldn’t sign" << obj  <<std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << *this << " executed" << form << std::endl;
    }catch(std::exception &e)
    {
         std::cout << *this << " not exectude"  << "because" << e.what() <<  std::endl;
    }
}