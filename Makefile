# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 20:48:54 by frosa-ma          #+#    #+#              #
#    Updated: 2022/06/27 00:58:16 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all bonus clean fclean re

NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
HEADER		= so_long.h

B_NAME		= so_long_bonus

LIBFT	= libft.a
MLX		= mlx.a
IFT		= -Ilibft -Llibft -lft
IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11

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

B_SRCS	= \
	main_bonus.c \
	map_bonus.c \
	validate_sides_bonus.c \
	validate_attributes_bonus.c \
	init_bonus.c \
	events_bonus.c \
	render_bonus.c \
	controls_bonus.c \
	movement_bonus.c \
	ft_alt_gnl_bonus.c \
	anim_player_bonus.c \
	anim_slime_bonus.c \
	anim_exit_bonus.c \
	cleanup_bonus.c \
	validate_movement.c \
	init_utils_bonus.c

OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})
B_OBJS	= $(addprefix ${OBJSDIR}/, ${B_SRCS:%.c=%.o})

all: ${NAME}
bonus: ${NAME}_bonus

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${IFT} ${IMLX} -o $@

${NAME}_bonus: ${OBJSDIR} ${B_OBJS}
	${CC} ${CFLAGS} ${B_OBJS} ${IFT} ${IMLX} -o $@

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${LIBFT} ${MLX}
${B_OBJS}: | ${LIBFT} ${MLX}

${OBJSDIR}/%.o: src/%.c src/so_long.h Makefile
	${CC} ${CFLAGS} ${IFT} ${IMLX} -c $< -o $@

${OBJSDIR}/%.o: bonus/%.c bonus/so_long_bonus.h Makefile
	${CC} ${CFLAGS} ${IFT} ${IMLX} -c $< -o $@

${LIBFT}: | libft
	${MAKE} -C libft/

${MLX}: | mlx
	${MAKE} -C mlx/

libft:
	git clone https://github.com/ichmi/libft.git

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git mlx

clean:
	${MAKE} clean -C libft
	${MAKE} clean -C mlx
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf libft mlx ${NAME} ${NAME}_bonus

re: fclean all
