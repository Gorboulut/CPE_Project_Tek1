##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = solver

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
