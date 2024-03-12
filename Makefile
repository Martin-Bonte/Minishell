##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC		= 	lib/mini_printf.c 			\
			lib/my_getnbr.c 			\
			lib/my_put_nbr.c 			\
			lib/my_putchar.c 			\
			lib/my_putstr.c 			\
			lib/my_str_to_word_array.c 	\
			lib/my_strcpy.c 			\
			lib/my_strdup.c 			\
			lib/my_strncpy.c 			\
			lib/my_strlen.c 			\
			lib/my_strcat.c 			\
			lib/my_malloc.c 			\
			lib/my_memset.c 			\
			lib/my_strcmp.c 			\
										\
			src/minishell.c 			\
			src/parsing.c 				\
										\
			src/command/command.c 		\
			src/command/env.c 			\
			src/command/cd.c 			\
			src/command/setenv.c 		\
			src/command/unsetenv.c 		\

OBJ 	= 	$(SRC:.c=.o)

NAME    =   mysh

CFLAGS 	= 	-W -Wall -Wextra -Werror -Wpedantic -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) -lmy
	gcc -o $(NAME) $(OBJ)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@echo "Clean completed."

fclean: clean
	@echo "Full Cleaning..."
	@rm -f $(NAME)
	@echo "Full Clean completed."

re:    fclean all

debug: $(OBJ)
	gcc -o $(NAME) $(OBJ) -g

graphic: fclean
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -lcsfml-system -lcsfml-graphics -lcsfml-window
