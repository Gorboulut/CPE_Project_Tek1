##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC = main.c \
		map_creator.c	\
		algo.c \

OBJ = $(SRC:.c=.o)

NAME = generator

CFLAGS = -g

INCLUDE = -Wall -Wextra -I./include

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(INCLUDE)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re:	fclean all
