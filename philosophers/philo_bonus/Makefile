# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:24:56 by cgrayson          #+#    #+#              #
#    Updated: 2022/01/27 01:51:54 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= philo_bonus

HEADER		= philo_bonus.h

INCLUDE		= -lpthread

SRCS		= philo_bonus.c ft_error.c ft_init_bonus.c ft_launcher_bonus.c ft_utils_bonus.c

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