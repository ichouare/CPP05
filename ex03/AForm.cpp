#include "./AForm.hpp"
#include "AForm.hpp"


AForm::AForm():m_name("anonyme"),m_signed(false),m_grade_signed(0),m_grade_execute(0)
{

}

AForm::~AForm()
{

}

AForm::AForm(std::string m_name, int m_grade_signed, int m_grade_execute):m_name(m_name),m_signed(false),m_grade_signed(m_grade_signed),m_grade_execute(m_grade_execute)
{
    if(m_grade_execute <  1 || m_grade_execute < 1)
        AForm::GradeTooHighException();
    else if(m_grade_execute > 150 || m_grade_execute > 150)
        AForm::GradeTooLowException();
}

AForm::AForm(const AForm& original):m_name(original.getName()),m_signed(original.getSigned()),m_grade_signed(original.getSignGrade()),m_grade_execute(original.getExecuteGrade())
{

}

AForm& AForm::operator=(const AForm& original)
{
    if(this != &original)
        m_signed = original.getSigned();
    return(*this);
}


std::string AForm::getName() const 
{
    return (m_name);
}   

bool AForm::getSigned() const {
    return (m_signed);
}



int AForm::getSignGrade() const
{
    return m_grade_signed;
}

int AForm::getExecuteGrade() const
{
    return  m_grade_execute;
}

void AForm::beSigned(Bureaucrat obj)
{
        if (obj.getGrade()  >= 1 && obj.getGrade() <= this->m_grade_signed)
            this->m_signed = true;
        else
            AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException: out of range";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: out of range";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "NotSignedException: not signed AForm!";
}


std::ostream& operator<<(std::ostream& flux, const AForm& obj )
{
   flux << obj.getName();
    flux << " , AForm status: ";
   flux << obj.getSigned();
   flux << "grade required to sign it";
   flux << obj.getSignGrade();
   flux << "grade required to execute it";
   flux << obj.getExecuteGrade();
   flux << std::endl;
   return flux;
}