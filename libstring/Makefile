SRC	=	src/string.c	\
		src/string2.c	\
		src/string_cpy.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -fPIC -O2 -g -Iinclude/

LDFLAGS	=	-shared

NAME	=	libstring.so

TESTFLAG	=	-Iinclude -L.
TESTMAIN	=	main.c
TESTOUT	=	-lstring

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) test

re:	fclean all

test:
	$(CC) $(TESTFLAG) $(TESTMAIN) -o test $(TESTOUT)

.PHONY:	all clean fclean re test