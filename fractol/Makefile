# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 02:48:03 by cgrayson          #+#    #+#              #
#    Updated: 2021/10/26 20:19:52 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

HEAD	= includes/

SRCS	= srcs/ft_colours.c	srcs/ft_utils.c		srcs/ft_utils_2.c \
		srcs/ft_fractol.c	srcs/ft_hooks.c		srcs/main.c

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

.c.o:
		$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
		$(CC) $(SRCS) -I$(HEAD) minilibx/libmlx.a -o $(NAME) -lm -lX11 -lXext

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re