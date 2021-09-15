# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 14:30:06 by bben-yaa          #+#    #+#              #
#    Updated: 2021/09/15 15:18:15 by bben-yaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER		= server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRCS_SERVER	= ./server.c \

SRCS_CLIENT = ./client.c \


SRCS_SERVER_BONUS = ./server_bonus.c \

SRCS_CLIENT_BONUS = ./client_bonus.c \

OBJ_SERVER		= $(SRCS_SERVER:.c=.o)
OBJ_CLIENT		= $(SRCS_CLIENT:.c=.o)

OBJ_SERVER_BONUS	= $(SRCS_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS	= $(SRCS_CLIENT_BONUS:.c=.o)


RM			= rm -rf
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

.c.o:	${CC} ${CFLAGS} -c $< o ${<:.c=.o}

all : 		${SERVER} ${CLIENT}

${SERVER}:	$(OBJ_SERVER)
			$(CC) $(OBJ_SERVER) $(FLAGS)  -o $(SERVER)

${CLIENT}: 	$(OBJ_CLIENT)
			$(CC) $(OBJ_CLIENT) $(FLAGS) -o $(CLIENT)

${SERVER_BONUS}:	$(OBJ_SERVER_BONUS)
					$(CC) $(OBJ_SERVER_BONUS) $(FLAGS)  -o $(SERVER_BONUS)

${CLIENT_BONUS}: 	$(OBJ_CLIENT_BONUS)
					$(CC) $(OBJ_CLIENT_BONUS) $(FLAGS) -o $(CLIENT_BONUS)

bonus: 		${SERVER_BONUS} ${CLIENT_BONUS}

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) ${OBJ_SERVER_BONUS} ${OBJ_CLIENT_BONUS}

fclean:	clean
		$(RM) ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}

re : 	fclean  all
