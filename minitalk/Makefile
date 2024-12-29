# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guest <guest@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:34:42 by <sthrodri>        #+#    #+#              #
#    Updated: 2024/12/28 16:10:33 by guest            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT =	client
NAME_SERVER =	server
NAME_MINITALK =	minitalk
CC =	cc
CFLAGS =	-Wall -Wextra -Werror
SRC_CLIENT =	client.c
SRC_SERVER =	server.c
SRC_MINITALK =	minitalk.c
OBJ_CLIENT =	$(SRC_CLIENT:.c=.o)
OBJ_SERVER =	$(SRC_SERVER:.c=.o)
OBJ_MINITALK =	$(SRC_MINITALK:.c=.o)
RM =	rm -f

all:	$(NAME_MINITALK)

$(NAME_MINITALK):	$(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_MINITALK)
	$(CC) $(CFLAGS) -o $(NAME_MINITALK) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_MINITALK)

$(NAME_CLIENT):	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_MINITALK)

fclean:	clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_MINITALK)

re:	fclean	all

.PHONY:	all	clean	fclean	re
