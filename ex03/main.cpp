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
        AForm* rrf = NULL;
    try
    {
        Bureaucrat b("dave", 40);
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        b.signForm(*rrf);
        rrf->execute(b);
        delete rrf;
    }
    catch (std::exception & e)
    {
        delete rrf;
        std::cout << e.what() << std::endl;
    }
    puts("hete");
    atexit(test);
    // if(rrf)
    return 0;
}