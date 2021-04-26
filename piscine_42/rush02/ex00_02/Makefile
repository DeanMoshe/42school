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

SRCS		= ft_check_number.c ft_cmp.c ft_putstr.c ft_recursive_power.c ft_search.c ft_strlen.c main.c

OBJS		= ${SRCS:.c=.o}

HEAD		= ft.h

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
