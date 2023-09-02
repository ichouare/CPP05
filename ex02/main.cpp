#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./AForm.hpp"
int main()
{
    try
    {
        Bureaucrat b( "me", 10);
        ShrubberyCreationForm d("file1");
        d.beSigne(b);
        d.execute(b);
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

   


}