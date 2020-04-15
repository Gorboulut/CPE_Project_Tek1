##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

CC = gcc

SRC = 	my_putchar.c	\
				my_itoa.c	\
				my_putstr.c	\
				my_strcat.c	\
				my_strdup.c	\
				my_number.c	\
				my_put_nbr.c	\
				my_revstr.c	\
				my_strcpy.c	\
				my_strlen.c	\
				suppr_space.c	\
				my_realloc.c	\
				my_strcmp.c	\
				my_strlowcase.c

OBJ = 	$(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f *~
