#ifndef PRESIDENT_H
#define PRESIDENT_H

#include "./AForm.hpp"
#include <fstream>

class Bureaucrat;

class PresidentialPardonForm: public AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string m_target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& original);
        const PresidentialPardonForm& operator=(const PresidentialPardonForm& original);
         std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string m_target;
};



std::ostream &operator<<(std::ostream &flux, const PresidentialPardonForm& obj);

#endif 