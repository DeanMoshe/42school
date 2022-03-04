# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:52:25 by cgrayson          #+#    #+#              #
#    Updated: 2022/01/27 01:51:47 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

HEADER		= philo.h

INCLUDE		= -lpthread

SRCS		= philo.c ft_error.c ft_init.c ft_launcher.c ft_utils.c

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%.o: 		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $<  -o $(<:.c=.o)

.PHONY:		all clean fclean re