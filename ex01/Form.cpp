#include "./Form.hpp"



Form::Form():m_name("anonyme"),m_signed(false),m_grade_signed(0),m_grade_execute(0)
{

}

Form::~Form()
{

}

Form::Form(std::string m_name, int m_grade_signed, int m_grade_execute):m_name(m_name),m_signed(false),m_grade_signed(m_grade_signed),m_grade_execute(m_grade_execute)
{
   if(m_grade_signed < 1 || m_grade_execute < 1)
    Form::GradeTooHighException();
    else if(m_grade_signed > 150 || m_grade_execute > 150)
        Form::GradeTooLowException();
}

Form::Form(const Form& original):m_name(original.getName()),m_signed(false),m_grade_signed(original.getSignGrade()),m_grade_execute(original.getExecuteGrade())
{

}

Form& Form::operator=(const Form& original)
{
    if(this == &original)
        return (*this);
    // this->m_name = original.m_name;
    this->m_signed = original.m_signed;
    // this->m_grade_execute = original.m_grade_execute;
    // this->m_grade_sign = original.m_grade_sign;
    return(*this);
}


std::string Form::getName() const 
{
    return (m_name);
}   

bool Form::getSigned() const {
    return (m_signed);
}

int Form::getSignGrade() const
{
    return m_grade_signed;
}



int Form::getExecuteGrade() const
{
    return  m_grade_execute;
}

void Form::beSigned(Bureaucrat& obj)
{   
        if(obj.getGrade() <= this->m_grade_signed)
            this->m_signed = true;
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


std::ostream& operator<<(std::ostream& flux, const Form& obj )
{
   flux << obj.getName();
    flux << " , Form status: ";
    if(obj.getSigned() == 1)
            flux <<  "True";
    else
        flux << "False";
   flux << " grade required to sign it ";
   flux << obj.getSignGrade();
   flux << " grade required to execute it ";
   flux << obj.getExecuteGrade();  
   return flux;
}