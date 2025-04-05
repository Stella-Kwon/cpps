NAME = ClapTrap

COMPILER = c++

SRC = 	main.cpp\
		ClapTrap.cpp

FLAGS = -Wall -Wextra -Werror -std=c++20 $(EXTRA_FLAGS)
EXTRA_FLAGS = -Wshadow -Wno-shadow

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

	@echo "$(Green)   ||||||||  $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo " $(Green)        ||  $(Ending)"
	@echo " $(Green)    |||||   $(Ending)"
	@echo "$(Green)   ||        $(Ending)"
	@echo "$(Green)  ||         $(Ending)"
	@echo "$(Green)  |||||||||| $(Ending)" 
	@echo "                               "
	@echo "$(Green)   ||||||||  $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo "$(Green)   ||||||||  $(Ending)"
	@echo "                               "
	@echo "$(Green)   ||||||||  $(Ending)"
	@echo "$(Green)  ||      || $(Ending)"
	@echo " $(Green)        ||  $(Ending)"
	@echo " $(Green)    |||||   $(Ending)"
	@echo "$(Green)   ||        $(Ending)"
	@echo "$(Green)  ||         $(Ending)"
	@echo "$(Green)  |||||||||| $(Ending)" 
	@echo "                               "
	@echo "$(Green) ||||||||||  $(Ending)"
	@echo "$(Green) ||          $(Ending)"
	@echo "$(Green) ||          $(Ending)"
	@echo "$(Green) ||||||||    $(Ending)"
	@echo "$(Green)         ||  $(Ending)"
	@echo "$(Green) ||      ||  $(Ending)"
	@echo "$(Green)  ||||||||   $(Ending)"
	@echo "                      "
	@echo "$(Red) 🎉🎉🎉 HAPPY NEW YEAR! 🎉🎉🎉  $(Ending)"
	@echo "$(Green)⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐  $(Ending)"
	@echo "$(Red) 🎁✨ Wishing you a joyful 2025! 🎁  $(Ending)"
	@echo "\n$(Yellow)=> $(NAME) HAS BEEN CREATED$(Ending)\n"

%.o : %.cpp
	@$(COMPILER) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

Red = \033[0;31m
Green = \033[0;32m
Yellow = \033[0;33m
Blue = \033[0;34m
Magenta = \033[0;35m
Cyan = \033[0;36m
White = \033[0;37m
Ending = \033[0m
Brown = \033[38;5;94m 