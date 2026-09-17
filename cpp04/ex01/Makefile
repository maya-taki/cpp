NAME = animal

CXX = c++
INCLUDE = -I includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE)


SRC =	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \
		Brain.cpp \
		main.cpp

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

$(NAME) : $(OBJ)
	@$(CXX) $(FLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(FLAGS) -c $< -o $@
	@$(call show_progress, $<)

all : $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean clean re all
