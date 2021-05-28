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

LIST		= 	ft_strncmp.c		ft_isalpha.c		ft_memchr.c			ft_strchr.c\
				ft_atoi.c			ft_isascii.c		ft_memcmp.c			ft_strdup.c\
				ft_bzero.c			ft_isdigit.c		ft_memcpy.c			ft_strlcat.c\
				ft_calloc.c			ft_isprint.c		ft_memmove.c		ft_strlcpy.c\
				ft_isalnum.c		ft_memccpy.c		ft_memset.c			ft_strlen.c\
				ft_itoa.c			ft_putendl_fd.c		ft_putstr_fd.c		ft_strjoin.c\
				ft_putchar_fd.c		ft_putnbr_fd.c		ft_split.c			ft_strmapi.c\
				ft_strnstr.c		ft_strrchr.c		ft_tolower.c		ft_toupper.c\
				ft_strtrim.c		ft_substr.c

LIST_B		=	ft_lstadd_back.c	ft_lstclear.c		ft_lstiter.c		ft_lstmap.c\
				ft_lstsize.c		ft_lstadd_front.c	ft_lstdelone.c		ft_lstlast.c\
				ft_lstnew.c			ft_btreenew_bonus.c	ft_btree_apply_infix_bonus.c\
				ft_btree_apply_prefix_bonus.c			ft_btree_apply_suffix_bonus.c\
				ft_islower_bonus.c	ft_isupper_bonus.c	ft_strcat_bonus.c	ft_strcmp_bonus.c\
				ft_strcpy_bonus.c	ft_strncat_bonus.c	ft_strncpy_bonus.c	ft_atol_bonus.c\
				ft_atoll_bonus.c

OBJ			=	$(patsubst %.c,%.o,$(LIST))
OBJ_B		=	$(patsubst %.c,%.o,$(LIST_B))

RM			= rm -f

COMPILER	=	gcc
AR			=	ar rcs
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $?

%.o:		%.c
			$(COMPILER) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus:		
			@make OBJ="$(OBJ_B)" all

clean:		
			$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

make:		all

.PHONY:		all clean fclean re make
