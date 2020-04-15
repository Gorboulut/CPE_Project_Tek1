##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

all: $(NAME)
	make -C solver/
	make -C generator/

clean:
	make clean -C solver/
	make clean -C generator/

fclean:
	make fclean -C solver/
	make fclean -C generator/
	rm -f *~

re:	fclean all
