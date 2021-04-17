##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bsq
##

CC 	= 	gcc

SRC 	=		src/main.c\
				src/d_tiret.c\
				src/l_tiret.c\
				src/r_tiret.c\
				src/R_tiret.c\
				src/t_tiret.c\
				lib/my_putstr.c

OBJ     = 		$(SRC:.c=.o)

NAME	=		my_ls

CFLAGS 	=	-W -Wall -Wextra -pedantic


all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all