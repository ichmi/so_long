# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 20:48:54 by frosa-ma          #+#    #+#              #
#    Updated: 2022/06/22 21:59:45 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all bonus clean fclean re

NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= so_long.h
SRCS	= \
	main.c \
	map.c \
	validate_sides.c \
	validate_attributes.c \
	init.c \
	events.c \
	render.c \
	controls.c \
	movement.c \
	ft_alt_gnl.c \
	cleanup.c

OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

LIBFT	= libft.a
MLX		= mlx.a
IFT		= -Ilibft -Llibft -lft
IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11

all: ${NAME}

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${IFT} ${IMLX} -o $@

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${LIBFT} ${MLX}

${OBJSDIR}/%.o: %.c ${Header} Makefile
	${CC} ${CFLAGS} ${IFT} ${IMLX} -c $< -o $@

${LIBFT}: | libft
	${MAKE} -C libft/

${MLX}: | mlx
	${MAKE} -C mlx/

libft:
	git clone https://github.com/ichmi/libft.git

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git mlx

leak:
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} m1.ber

bonus: all

clean:
	${MAKE} clean -C libft
	${MAKE} clean -C mlx
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all
