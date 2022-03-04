# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 19:39:57 by cgrayson          #+#    #+#              #
#    Updated: 2022/02/01 05:32:13 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_B		= checker

HEADER		= includes/push_swap.h
HEADER_B	= includes/checker.h

SRCS		= srcs/ft_swap_stack.c		srcs/ft_struct_init.c\
			srcs/ft_stack_utils.c	srcs/ft_stack_create.c		srcs/ft_sort_utils.c\
			srcs/ft_small_cases.c	srcs/ft_rotate_stack.c		srcs/ft_reverse_rotate_stack.c\
			srcs/ft_push_stack.c	srcs/ft_exit.c				srcs/ft_big_cases_1.c\
			srcs/ft_big_cases_2.c	srcs/ft_big_cases_3.c		srcs/ft_big_cases_4.c

SRCS_B		= checker_bonus/main.c		checker_bonus/get_next_line.c		checker_bonus/get_next_line_utils.c

SRCS_S		= srcs/main.c

OBJS		= $(SRCS:.c=.o)
OBJS_S		= $(SRCS_S:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

RM			= rm -f

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_S)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_S)

$(NAME_B):	$(OBJS) $(OBJS_B)
			$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS) $(OBJS_B)
		
bonus:		$(NAME_B)

clean:
			$(RM) $(OBJS) $(OBJS_S) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

%.o: 		%.c $(HEADER) $(HEADER_B)
			$(CC) $(CFLAGS) -c $<  -o $(<:.c=.o)

.PHONY:		all clean fclean re bonus
