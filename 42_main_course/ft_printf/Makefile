# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 18:31:19 by cgrayson          #+#    #+#              #
#    Updated: 2021/07/07 19:47:14 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS_PATH	= srcs/

LIBFT_PATH	= libft/

LIBFT_LIB	= libft.a

HEAD_PATH	= includes/

SRCS_FILES	= ./srcs/ft_printf.c			./srcs/ft_format.c				./srcs/ft_checks.c\
			./srcs/ft_flags_1.c				./srcs/ft_flags_2.c				./srcs/ft_output_char.c\
			./srcs/ft_output_hexa_int.c		./srcs/ft_output_int.c			./srcs/ft_output_percent.c\
			./srcs/ft_output_pointer.c		./srcs/ft_output_string.c		./srcs/ft_alignment.c

SRCS_OBJS	= ${SRCS_FILES:.c=.o}

RM			= rm -f

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

LIBFT_OBJS	= ${LIBFT_PATH}*.o

LIBFTMAKE	= $(MAKE) -C ${LIBFT_PATH}

all:		${NAME}

${NAME}:	${SRCS_OBJS} pmake
			${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean:		clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:			fclean all

.PHONY:		all clean fclean re