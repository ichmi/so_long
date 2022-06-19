# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 20:48:54 by frosa-ma          #+#    #+#              #
#    Updated: 2022/06/19 16:25:31 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= map.c validate_sides.c validate_attributes.c
OBJS	= ${SRCS:.c=.o}

FT		= -Ilibft -Llibft -lft
X		= -Imlx -Lmlx -lXext -lX11
OBJS	= ${SRCS:.c=.o}

all: ${NAME}

# TODO: add CFLAGS eventually
${NAME}: ${OBJS}
	${CC} main.c ${OBJS} ${FT} ${X} -o ${NAME}

%.o: %.c
	${CC} ${FT} -c $^

clean:
	rm -f *.o

fclean: clean
	rm -f so_long

re: fclean all
