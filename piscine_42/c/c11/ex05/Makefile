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

SRCS		= srcs/do_op.c srcs/ft_p_fn.c srcs/ft_atoi.c srcs/ft_putstr.c srcs/ft_is_number.c srcs/ft_operators.c srcs/ft_putchar.c srcs/ft_putnbr.c

OBJS		= ${SRCS:.c=.o}

HEAD		= includes/ft.h

NAME		= do-op

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
