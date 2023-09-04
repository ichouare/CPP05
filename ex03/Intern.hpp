#ifndef INTERN_H
#define INTERN_H

#include "./AForm"

class Intern : public AForm
{
    Intern();
    ~Intern();
    Intern(const Intern& original);
    Intern& operator=(const Intern& original);
    AForm *makeForm(std::string name, std::string target);
}

#endif 