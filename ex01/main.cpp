#include "./Bureaucrat.hpp"

int main()
{
    // Bureaucrat bureaucrat("ash",9);
    // Form form("formName", 10, 50);
    // form.beSigned(bureaucrat);

    // std::cout << form.getSignal() << std::endl;
   try {
        Bureaucrat bureaucrat("ash",11);
        Form form("formName", 10, 15);
        bureaucrat.signForm(form);

        //std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


}