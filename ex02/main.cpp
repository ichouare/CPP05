#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./AForm.hpp"


int main()
{
    try
    {
        Bureaucrat b( "me", 137);
        ShrubberyCreationForm d("file1");
        b.signForm(d);
        b.executeForm(d);
        // std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;
    try
    {
        Bureaucrat b( "me", 20);
        RobotomyRequestForm d("file1");
        b.signForm(d);
        b.executeForm(d);
        std::cout << d << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}