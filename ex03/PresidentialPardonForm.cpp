#include "./PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5),m_target("MyFile")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string m_target):AForm("PresidentialPardonForm", 25, 5),m_target(m_target)
{
   
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original):AForm("PresidentialPardonForm", 25, 5),m_target(original.getTarget())
{
    
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
    if(this == &original)
        return (*this);
    this->m_target = original.m_target;
    return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(this->getSigned() == false)
        throw PresidentialPardonForm::NotSignedException();
    else if(executor.getGrade() > this->getExecuteGrade())
        throw PresidentialPardonForm::GradeTooHighException();
    else
    {
         std::cout << m_target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
    }

}


std::string PresidentialPardonForm::getTarget() const
{
    return m_target;
}

std::ostream &operator<<(std::ostream &flux, const PresidentialPardonForm& obj)
{
    flux << obj.getTarget();
    return flux;
}