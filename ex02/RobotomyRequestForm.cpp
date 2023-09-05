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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original):AForm("PresidentialPardonForm", 25, 5),m_target(original.getTarget())
{
  
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
    if(this->getSigned() == false)
        throw RobotomyRequestForm::NotSignedException();
    else if(executor.getGrade() > this->getExecuteGrade())
        throw RobotomyRequestForm::GradeTooHighException();
    else
    {

        std::cout << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
        std::cout << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
        std::cout << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
        std::cout << "     (     ,-'                  `." << std::endl;
        std::cout << "      `._,'     _   _             ;" << std::endl;
        std::cout << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
        std::srand(time(0)); // use current time as seed for random generator
        int random_variable = std::rand() ;
        if(random_variable % 2)
            std::cout << m_target << "has been robotomized successfully 50% of the time." << std::endl;
        else
            std::cout << m_target << "robotomy failed" << std::endl;
    }

}


std::string RobotomyRequestForm::getTarget() const
{
    return  m_target;
}

std::ostream &operator<<(std::ostream &flux, const RobotomyRequestForm& obj)
{

     flux << obj.getName();
    flux << " , Form status: ";
    flux << obj.getSigned();
   flux << " grade required to sign it ";
   flux << obj.getSignGrade();
   flux << " grade required to execute it ";
   flux << obj.getExecuteGrade(); 
   flux << "Form target : ";
    flux << obj.getTarget();
    return flux;
}