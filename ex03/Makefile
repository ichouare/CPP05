NAME = Exception

FLAG =  c++

FLAGS =  -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
 
HEADER =  ./Bureaucrat.hpp ./AForm.hpp  ./PresidentialPardonForm.hpp ./RobotomyRequestForm.hpp ./ShrubberyCreationForm.hpp ./Intern.hpp

SRC = ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp ./ShrubberyCreationForm.cpp ./Intern.cpp



OBJ =  $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ) 
		$(FLAG) $(FLAGS)  $^ -o $@


%.o : %.cpp ${HEADER} 
	$(FLAG) $(FLAGS)  $< -c -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all 