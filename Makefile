##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC		= 	lib/mini_printf.c \
			lib/my_getnbr.c \
			lib/my_put_nbr.c \
			lib/my_putchar.c \
			lib/my_putstr.c \
			lib/my_str_to_word_array.c \
			lib/my_strcpy.c \
			lib/my_strdup.c \
			lib/my_strncpy.c \
			lib/my_strlen.c \
			src/minishell.c \
			lib/my_strcat.c \
			src/command.c \
			src/env.c \
			src/cd.c \
			src/parsing.c \
			lib/my_strcmp.c \

OBJ 	= 	$(SRC:.c=.o)

NAME    =   mysh

CFLAGS 	= 	-Wall -Wextra -g

all:    $(OBJ)
	@rm -f $(NAME)
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
