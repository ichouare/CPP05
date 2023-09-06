#include "./Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern& original)
{
     *this = original;
}


Intern &Intern::operator=(const Intern &original)
{
    (void)original;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    int i = 0;
    AForm *form = NULL;

    std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    while(i < 3 && names[i] != name)
    {
        i++;
    }
    switch (i)
    {
    case 0:
       form = new  PresidentialPardonForm(target);
        break;
    case 1:
       form = new RobotomyRequestForm(target);
        break;
    case 2:
       form =  new ShrubberyCreationForm(target);
        break;
    default:
        throw Intern::NotfoundName();
        break;
    };
    return form;
}


const char * Intern::NotfoundName::what()  const throw()
{
     return "NotfoundName: this name not found could you change  the name. Thanks ";
}

