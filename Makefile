##
## EPITECH PROJECT, 2024
## B-MUL-100-PAR-1-1-myhunter-nicky.truong
## File description:
## Makefile
##

SRC=	source/main.c	\
		source/animation.c	\
		source/window_manager.c	\
		lib/my_strcmp.c	\
		lib/my_putstr.c	\
		lib/my_strlen.c	\
		lib/my_put_nbr.c	\
		lib/my_revstr.c	\
		lib/my_strdup.c

OBJ=	$(SRC:.c=.o)

NAME=	my_hunter

CFLAGS	+=	-Wall -Wextra -Werror

CSFMLFLAGS	+=	-l csfml-graphics -l csfml-system -l csfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
