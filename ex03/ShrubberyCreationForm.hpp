#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "./AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string m_target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);
        void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
    private:
        std::string m_target;
};


std::ostream &operator<<(std::ostream &flux, const ShrubberyCreationForm& obj);

#endif 