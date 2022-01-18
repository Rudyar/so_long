# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 16:35:41 by arudy             #+#    #+#              #
#    Updated: 2022/01/18 18:47:40 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix srcs/, main.c parsing/parse_input.c \
			parsing/parse_input_utils.c utils/ft_strlen.c \
			utils/ft_strnstr.c utils/get_next_line.c \
			utils/get_next_line_utils.c utils/ft_error.c)

OBJS	= ${SRCS:.c=.o}

NAME = so_long

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
