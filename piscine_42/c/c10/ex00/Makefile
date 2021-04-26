# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 17:30:07 by cgrayson          #+#    #+#              #
#    Updated: 2021/03/01 17:30:10 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_display_file.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_display_file.out

GCC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror


.c.o:		
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean

	
