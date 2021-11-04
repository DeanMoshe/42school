# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 19:39:57 by cgrayson          #+#    #+#              #
#    Updated: 2021/10/22 02:25:11 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

HEAD	= includes/

SRCS	= srcs/main.c			srcs/ft_swap_stack.c		srcs/ft_struct_init.c\
		srcs/ft_stack_utils.c	srcs/ft_stack_create.c		srcs/ft_sort_utils.c\
		srcs/ft_small_cases.c	srcs/ft_rotate_stack.c		srcs/ft_reverse_rotate_stack.c\
		srcs/ft_push_stack.c	srcs/ft_exit.c				srcs/ft_big_cases_1.c\
		srcs/ft_big_cases_2.c	srcs/ft_big_cases_3.c		srcs/ft_big_cases_4.c

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

.c.o:
		$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
		$(CC) $(CFLAGS) -I$(HEAD) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
