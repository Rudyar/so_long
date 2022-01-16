# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 16:35:41 by arudy             #+#    #+#              #
#    Updated: 2022/01/16 16:48:50 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix srcs/, so_long.c parsing/parse_input.c \
			utils/ft_strlen.c utils/ft_strnstr.c)

OBJS	= ${SRCS:.c=.o}

NAME = so_long

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} srcs/*.o -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
