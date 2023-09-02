#include "./RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45),m_target("MyFile")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string m_target):AForm("RobotomyRequestForm", 72, 45),m_target(m_target)
{
   
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
{
   *this = original;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
    if(this == &original)
        return (*this);
    this->m_target = original.m_target;
    return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(this->getSignal() == false)
        throw RobotomyRequestForm::NotSignedException();
    else if(executor.getGrade() > this->getSignalExecute())
        throw RobotomyRequestForm::GradeTooHighException();
    else
    {

    std::cout << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    std::cout << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    std::cout << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    std::cout << "     (     ,-'                  `." << std::endl;
    std::cout << "      `._,'     _   _             ;" << std::endl;
    std::cout << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    std::cout << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    std::cout << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    std::cout << "                \"Hb HH dF" << std::endl;
    std::cout << "                 \"HbHHdF" << std::endl;
    std::cout << "                  |HHHF" << std::endl;
    std::cout << "                  |HHH|" << std::endl;
    std::cout << "                  |HHH|" << std::endl;
    std::cout << "                  |HHH|" << std::endl;
    std::cout << "                  |HHH|" << std::endl;
    std::cout << m_target << "has been robotomized successfully 50% of the time." << std::endl;
    }

}


std::string ShrubberyCreationForm::getTarget() const
{
    return  m_target;
}

std::ostream &operator<<(std::ostream &flux, const RobotomyRequestForm& obj)
{
    flux << obj.getTarget();
    return flux;
}