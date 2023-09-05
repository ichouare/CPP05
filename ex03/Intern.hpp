#ifndef INTERN_H
#define INTERN_H
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./AForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& original);
        Intern& operator=(const Intern& original);
        AForm *makeForm(std::string name, std::string target);
};

#endif 