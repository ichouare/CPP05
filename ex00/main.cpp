#include "./Bureaucrat.hpp"

int main()
{
    try
    {
         Bureaucrat b( "me", 10);
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
            Bureaucrat C("Dave", 0);
            C.decrementGrade();

    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
            Bureaucrat C("Dave", 150);
            C.incrementGrade();

    }
    catch(std::exception & e)
    {
         std::cerr << e.what() << '\n';
    }

    try
    {
            Bureaucrat E("Dave", -1);
            // Bureaucrat e("Dave", 0);
            // std::cout << e << std::endl;
            // e.decrementGrade();

    }
    catch(std::exception & e)
    {
         std::cerr << e.what() << '\n';
    }


}