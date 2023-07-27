SRC	=	src/llist.c		\
		src/node_insert.c	\
		src/node_get.c		\
		src/node_set.c		\
		src/node_remove.c	\
		src/node_swap.c		\
		src/node_util.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -fPIC -O2 -g -Iinclude/

LDFLAGS	=	-shared

NAME	=	liblinked.so

TESTFLAG	=	-Iinclude -L.
TESTMAIN	=	main.c
TESTOUT	=	-llinked

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
