# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 14:30:06 by bben-yaa          #+#    #+#              #
#    Updated: 2021/09/08 12:31:20 by bben-yaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER	= server.c\
SRCS_CLIENT = client.c\
OBJ_SERVER	= $(SRCS_SERVER:.c=.o)
OBJ_CLIENT	= $(SRCS_CLIENT:.c=.o)
RM			= /bin/rm -rf
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
S			= server
C			= client
#PRINTF		= -L ./my_printf/ -lftprintf

%.o : %.c
	$(CC) -c $(FLAGS) $<

all : server client

server :

		$(CC) $(FLAGS) $(SRCS_SERVER) $(EXEC) $(S)

client : $(OBJ_CLIENT)

		$(CC) $(FLAGS) $(SRCS_CLIENT) $(EXEC) $(C)

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:	clean
		$(RM) server client  

re : clean  all
