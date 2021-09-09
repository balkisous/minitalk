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

CLIENT		= client
SERVER		= server

SRCS_SERVER	= ./server.c \

SRCS_CLIENT = ./client.c \

OBJ_SERVER	= $(SRCS_SERVER:.c=.o)
OBJ_CLIENT	= $(SRCS_CLIENT:.c=.o)

RM			= rm -rf
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

.c.o:	${CC} ${CFLAGS} -c $< o ${<:.c=.o}

all : 		${SERVER} ${CLIENT}

${SERVER}:	$(OBJ_SERVER)
			$(CC) $(OBJ_SERVER) $(FLAGS)  -o $(SERVER)

${CLIENT}: 	$(OBJ_CLIENT)
			$(CC) $(OBJ_CLIENT) $(FLAGS) -o $(CLIENT)

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:	clean
		$(RM) ${SERVER} ${CLIENT}  

re : 	fclean  all
