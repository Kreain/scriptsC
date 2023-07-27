SRC	=	src/client.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -fPIC -O2 -g -Iinclude/ -std=c11

LDFLAGS	=	-shared

NAME	=	libclient.so

CLIENTFLAG	=	-Iinclude -L.
CLIENTMAIN	=	main.c
CLIENTOUT	=	-lclient

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) client_exec

re:	fclean all

client:
	$(CC) $(CLIENTFLAG) $(CLIENTMAIN) -o client_exec $(CLIENTOUT)

.PHONY:	all clean fclean re client
