# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 14:23:57 by cgrayson          #+#    #+#              #
#    Updated: 2021/02/28 14:24:01 by cgrayson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

gcc -c -Wall -Wextra -Werror ft_putchar.c ft_strcmp.c ft_swap.c ft_putstr.c ft_strlen.c
ar rc libft.a ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o