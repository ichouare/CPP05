#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./AForm.hpp"
int main()
{
    try
    {
        Bureaucrat b( "me", 140);
        ShrubberyCreationForm d("file1");
        d.beSigned(b);
        // d.execute(b);
        b.executeForm(d);
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

   


}