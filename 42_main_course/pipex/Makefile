# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 14:17:51 by cgrayson          #+#    #+#              #
#    Updated: 2021/10/11 01:08:13 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= srcs/main.c			srcs/ft_putstr_fd.c				srcs/ft_putendl_fd.c\
			srcs/ft_split.c		srcs/ft_strjoin.c				srcs/ft_strlcpy.c\
			srcs/ft_strlen.c	srcs/ft_strncmp.c				srcs/ft_pipex_func.c\
			srcs/ft_strdup.c

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs

all:	$(NAME)

$(NAME):$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
