# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 20:33:12 by skwon2            #+#    #+#              #
#    Updated: 2024/12/03 21:34:51 by skwon2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HordeZombies

COMPILER = c++

INC = 

SRC = 	main.cpp\
		Zombie.cpp\
		ZombieHorde.cpp

FLAGS = -Wall -Wextra -Werror -std=c++20

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(COMPILER) $(FLAGS) $(INC) -o $(NAME) $(OBJ)

	@echo "$(Green)                  ⭐                $(Ending)"
	@echo "$(Green)                  *                 $(Ending)"
	@echo "$(Green)                 ***                $(Ending)"
	@echo "$(Green)                *****               $(Ending)"
	@echo "$(Green)               *******              $(Ending)"
	@echo "$(Green)              *********             $(Ending)"
	@echo "$(Green)             ***********            $(Ending)"
	@echo "$(Green)            *************           $(Ending)"
	@echo "$(Green)           v***v*****v***v          $(Ending)"
	@echo "$(Green)          *v*v***v*v**v*v**         $(Ending)"
	@echo "$(Green)         ***v*****v****v****        $(Ending)"
	@echo "$(Green)        *********************       $(Ending)"
	@echo "$(Green)       ***********************      $(Ending)"
	@echo "$(Green)      *************************     $(Ending)"
	@echo "$(Green)     ***************************    $(Ending)"
	@echo "$(Green)    *****************************   $(Ending)"
	@echo "$(Green)   **********            *********  $(Ending)"
	@echo "$(Brown)              ||||||||             $(Ending)"
	@echo "$(Brown)              ||||||||             $(Ending)"
	@echo "$(Brown)              ||||||||             $(Ending)"
	@echo "$(Brown)              ||||||||             $(Ending)"
	@echo "$(Brown)              ||||||||             $(Ending)"
	@echo "$(Brown)              |______|             $(Ending)"
	@echo "$(Brown)                                   $(Ending)"
	@echo "$(Red)  🎄🎁🎅🎉 Merry Christmas! 🎅🎁🎄   $(Ending)"
	@echo "$(Green)⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐  $(Ending)"
	@echo "$(Red)🎄🎅🎁✨ Wishing you a joyful Christmas! 🎁🎅🎄  $(Ending)"
	@echo "\n$(Yellow)=> $(NAME) HAS BEEN CREATED$(Ending)\n"

%.o : %.cpp
	@$(COMPILER) $(FLAGS) $(INC) -c $< -o $@

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