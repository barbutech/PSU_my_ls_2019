##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC 	=	src/my_ls.c						\
			src/my_putstr.c					\
			src/my_str_allocate_and_cat.c	\
			src/my_strlen.c					\
			src/flags_error.c				\
			src/my_unsigned_putchar.c		\
			src/flag_l_params.c				\
			src/my_put_nbr.c				\
			src/my_putchar.c 				\
			src/my_strcmp.c					\
			src/cases.c						\

OBJ 	= 	$(SRC:.c=.o)

CC		=	gcc -g3

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

test_run:
		gcc -o unit_test bonus/test_with_multiple_flags.c $(SRC) -lcriterion
		./unit_test

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
