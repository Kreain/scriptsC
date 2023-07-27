SRC	=	src/server.c		\
		src/exceptions.c	\
		src/init_server.c	\
		src/server_set.c	\
		src/await.c			\
		src/transfer.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -fPIC -O2 -g -Iinclude/  -std=c11

LDFLAGS	=	-shared

NAME	=	libserver.so

SERVERFLAG	=	-Iinclude -L.
SERVERMAIN	=	main.c
SERVEROUT	= -lserver

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) server_exec

re:	fclean all

server:
	$(CC) $(SERVERFLAG) $(SERVERMAIN) -o server_exec $(SERVEROUT)

.PHONY:	all clean fclean re server