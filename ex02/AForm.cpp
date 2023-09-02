#include "./AForm.hpp"
#include "AForm.hpp"


AForm::AForm():m_name("anonyme"),m_signal(false),m_grade_sign(0),m_grade_execute(0)
{

}

AForm::~AForm()
{

}

AForm::AForm(std::string m_name, int m_grade_signed, int m_grade_execute):m_name(m_name),m_signal(false),m_grade_sign(m_grade_sign),m_grade_execute(m_grade_execute)
{
    if(m_grade_execute < 0 || m_grade_execute < 0)
        AForm::GradeTooHighException();
    else if(m_grade_execute > 150 || m_grade_execute > 150)
        AForm::GradeTooLowException();
}

AForm::AForm(const AForm& original):m_name(original.getName()),m_signal(original.getSignal()),m_grade_sign(original.getSignalSign()),m_grade_execute(original.getSignalExecute())
{

}

AForm& AForm::operator=(const AForm& original)
{
    if(this != &original)
        m_signal = original.getSignal();
    return(*this);
}


std::string AForm::getName() const 
{
    return (m_name);
}   

bool AForm::getSignal() const {
    return (m_signal);
}

int AForm::getSignalSign() const
{
    return m_grade_sign;
}

int AForm::getSignalExecute() const
{
    return  m_grade_execute;
}


void AForm::beSigne(Bureaucrat obj)
{
        if (obj.getGrade()  >= 0 && obj.getGrade() <= this->m_grade_sign)
            this->m_signal = true;
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
   flux << obj.getSignal();
   flux << "grade required to sign it";
   flux << obj.getSignalSign();
   flux << "grade required to execute it";
   flux << obj.getSignalExecute();
   flux << std::endl;
   return flux;
}