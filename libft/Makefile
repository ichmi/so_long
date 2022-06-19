# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 17:12:17 by frosa-ma          #+#    #+#              #
#    Updated: 2022/06/18 20:30:45 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re bonus

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

B_SRCS = \
	./ft_lstnew.c \
	./ft_lstadd_front.c \
	./ft_lstsize.c \
	./ft_lstlast.c \
	./ft_lstadd_back.c \
	./ft_lstdelone.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_lstmap.c

M_SRCS = \
	./ft_isalpha.c \
	./ft_isdigit.c \
	./ft_isalnum.c \
	./ft_isascii.c \
	./ft_isprint.c \
	./ft_strlen.c \
	./ft_memset.c \
	./ft_bzero.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_strlcpy.c \
	./ft_strlcat.c \
	./ft_toupper.c \
	./ft_tolower.c \
	./ft_strchr.c \
	./ft_strrchr.c \
	./ft_strncmp.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_strnstr.c \
	./ft_atoi.c \
	./ft_calloc.c \
	./ft_strdup.c \
	./ft_substr.c \
	./ft_strjoin.c \
	./ft_strtrim.c \
	./ft_split.c \
	./ft_itoa.c \
	./ft_strmapi.c \
	./ft_striteri.c \
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
	./ft_putchar.c \
	./ft_putstr.c \
	./ft_putnbr.c \
	./ft_putunbr.c \
	./ft_putnbr_hex.c \
	./ft_ultoa.c \
	./ft_utoab.c \
	./ft_utoa.c \
	./ft_putptr.c \
	./ft_putnstr.c \
	./ft_strjoins.c \
	./ft_gnl.c

M_OBJS = ${M_SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}

all: ${NAME}

${NAME}: ${M_OBJS}
	@ar rc ${NAME} ${M_OBJS}

bonus: ${B_OBJS}
	@ar rc ${NAME} ${B_OBJS}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -f ${M_OBJS} ${B_OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
