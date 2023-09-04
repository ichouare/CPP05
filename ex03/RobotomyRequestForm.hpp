#ifndef ROBOTOMYFORM_H
#define ROBOTOMYFORM_H

#include "./AForm.hpp"
#include <fstream>
#include <stdlib.h>
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm: public AForm{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string m_target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& original);
        std::string getTarget() const;
        const RobotomyRequestForm& operator=(const RobotomyRequestForm& original);
        void execute(Bureaucrat const & executor) const;
    private:
        std::string m_target;
};



std::ostream &operator<<(std::ostream &flux, const RobotomyRequestForm& obj);

#endif 