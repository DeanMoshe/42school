# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 18:37:59 by cgrayson          #+#    #+#              #
#    Updated: 2021/04/30 18:37:59 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a

LIST		= 	ft_isalpha.c		ft_atoi.c			ft_isdigit.c		ft_strlen.c\
				ft_itoa.c			ft_putchar_fd.c		ft_numlen.c			ft_uitoa.c\
				ft_numlen_base.c	ft_putnbr_base.c	ft_itoa_base.c

OBJ			=	$(patsubst %.c,%.o,$(LIST))

RM			= rm -f

COMPILER	=	gcc
AR			=	ar rcs
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $?

%.o:		%.c
			$(COMPILER) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:		
			$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

make:		all

.PHONY:		all clean fclean re make
