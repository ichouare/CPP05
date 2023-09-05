#include "./RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137),m_target("MyFile")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string m_target):AForm("ShrubberyCreationForm", 145, 137),m_target(m_target)
{
   
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original):AForm("PresidentialPardonForm", 25, 5),m_target(original.getTarget())
{

}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
    if(this == &original)
        return (*this);
    this->m_target = original.m_target;
    return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(this->getSigned() == false)
        throw ShrubberyCreationForm::NotSignedException();
    else if(executor.getGrade() > this->getExecuteGrade())
        throw ShrubberyCreationForm::GradeTooHighException();
    else
    {
        std::string fileName =  this->getTarget() + "_target";
        std::ofstream file;
        file.open(fileName.data(), std::ios::trunc);
        if(!file.is_open())
        {
            std::cout << "file not open" << std::endl;
        }
    file << "                      ___" << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `." << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    file << "                \"Hb HH dF" << std::endl;
    file << "                 \"HbHHdF" << std::endl;
    file << "                  |HHHF" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  dHHHb" << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;
    file.close();
    }

}

std::string ShrubberyCreationForm::getTarget() const
{
    return  m_target;
}

std::ostream &operator<<(std::ostream &flux, const ShrubberyCreationForm& obj)
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