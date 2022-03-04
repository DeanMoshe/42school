/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:37:17 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:27:46 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_args(char *str, t_info *desc, int *args)
{
	long	num;
	bool	space;

	space = true;
	while (*str)
	{
		if (space && *str != ' ')
		{
			num = ft_push_atoi(str, desc);
			ft_push_end(desc, num);
			(*args)++;
			ft_check_duplicates(desc);
		}
		space = *str == ' ';
		str++;
	}
}

int	ft_read_args(int argc, char **argv, t_info *desc)
{
	int	i;
	int	args;

	i = 1;
	args = 0;
	while (i < argc)
	{
		ft_push_args(argv[i], desc, &args);
		i++;
	}
	if (!(desc->stack_a->first))
		ft_error(desc, NULL, NULL);
	return (args);
}

void	ft_check_duplicates(t_info *desc)
{
	t_elem	*elem1;
	t_elem	*elem2;

	elem1 = desc->stack_a->first;
	elem2 = desc->stack_a->first;
	while (elem1)
	{
		elem2 = desc->stack_a->first;
		while (elem2)
		{
			if (elem2->value == elem1->value && elem2 != elem1)
				ft_error(desc, NULL, NULL);
			elem2 = elem2->next;
		}
		elem1 = elem1->next;
	}
}
