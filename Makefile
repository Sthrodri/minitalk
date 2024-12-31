NAME_CLIENT =	client
NAME_SERVER =	server
CC =	cc
CFLAGS =	-Wall -Wextra -Werror
SRC_CLIENT =	client.c
SRC_SERVER =	server.c
OBJ_CLIENT =	$(SRC_CLIENT:.c=.o)
OBJ_SERVER =	$(SRC_SERVER:.c=.o)
RM =	rm -f

all:	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:	clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:	fclean	all

.PHONY:	all	clean	fclean	re
