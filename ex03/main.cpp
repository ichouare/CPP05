#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./AForm.hpp"
#include "./Intern.hpp"


void test()
{
    system("leaks Exception");
}
int main()
{
    // atexit(test);
    AForm* rrf;
    try
    {
        Bureaucrat b("dave", 15);
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if(rrf)
        {
            b.signForm(*rrf);
            rrf->execute(b);
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    delete rrf;
    return 0;
}