#include "./Form.hpp"



Form::Form():m_name("anonyme"),m_signal(false),m_grade_sign(0),m_grade_execute(0)
{

}

Form::~Form()
{

}

Form::Form(std::string m_name, int m_grade_signed, int m_grade_execute):m_name(m_name),m_signal(flase),m_grade_sign(m_grade_sign),m_grade_execute(m_grade_execute)
{
   if(m_grade_execute < 0 || m_grade_execute < 0)
    Form::GradeTooHighException();
    else if(m_grade_execute > 150 || m_grade_execute > 150)
        Form::GradeTooLowException();
}

Form::Form(const Form& original)
{
    this = original;
}

Form& Form::operator=(const Form& original)
{
    if(this == &original)
        return (*this);
    this->m_name = original.m_name;
    this->m_signal = original.m_signal;
    this->m_grade_execute = original.m_grade_execute;
    this->m_grade_sign = original.m_grade_sign;
    return(*this);
}


std::string Form::getName() const 
{
    return (m_name);
}   

bool Form::getSignal() const {
    return (m_signal);
}

int Form::getSignalSign() const
{
    return m_grade_sign;
}



int Form::getSignalExecute() const
{
    return  m_grade_execute;
}

void Form::beSigne(Bureaucrat obj)
{
        if(obj.m_grade <= this->m_grade_sign)
            this->m_signal = true;
        else
            Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException: out of range";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: out of range";
}


std::ostream& operator<<(std::ostream& flux, const Form obj )
{
   
   flux << obj.getName();
flux << " , Form status: ";
   flux << obj.getSignal();
   flux << "grade required to sign it";
   flux << obj.getSignalSign();
   flux << "grade required to execute it";
   flux << obj.getSignalExecute();
   flux << std::endl;
   return flux;
}