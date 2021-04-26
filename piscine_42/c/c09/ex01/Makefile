# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 15:33:07 by cgrayson          #+#    #+#              #
#    Updated: 2021/02/28 15:33:48 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_strcmp.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c

OBJS		= ${SRCS:.c=.o}

HEAD		= includes

NAME		= libft.a

GCC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

LIB			= ar rc

.c.o:		
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

make:		all

.PHONY:		all clean fclean re make