##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for bistro
##

SRC 	=	main.c	\
				game.c	\
				tab.c	\
				player.c	\
				ai.c	\
				ai_sec.c	\

OBJ 	= 	$(SRC:.c=.o)

NAME 	= 	matchstick

CFLAGS = -W -Wall -Wextra -lmy -L./lib/my -I./include -g

all: 	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
