# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:39:23 by cgrayson          #+#    #+#              #
#    Updated: 2021/03/11 13:39:30 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_binari_search.c ft_console_file.c ft_file_read.c ft_go_for_matrix.c ft_output.c ft_mas_free.c ft_putstr.c ft_search_for_line.c ft_search.c
			
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
