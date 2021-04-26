# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 20:00:24 by cgrayson          #+#    #+#              #
#    Updated: 2021/03/03 20:00:28 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_check_number.c srcs/ft_cmp.c srcs/ft_putstr.c srcs/ft_recursive_power.c srcs/ft_search.c srcs/ft_strlen.c srcs/letters_value.c srcs/main.c

OBJS		= ${SRCS:.c=.o}

HEAD		= includes/ft.h

NAME		= rush-02

GCC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror


.c.o:		
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -include ${HEAD}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

make:		all

.PHONY:		all clean fclean re make

.SILENT:
