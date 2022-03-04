/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:10:57 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:20 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_free_stack(t_stack *stack)
{
	t_elem	*elem;

	if (stack)
	{
		elem = stack->first;
		while (elem)
		{
			stack->first = stack->first->next;
			free(elem);
			elem = NULL;
			elem = stack->first;
		}
		free(stack);
		stack = NULL;
	}
}

void	ft_free_all(t_info *desc, int *min_a, int *min_b)
{
	if (desc->stack_a)
		ft_free_stack(desc->stack_a);
	if (desc->stack_b)
		ft_free_stack(desc->stack_b);
	if (desc)
	{
		free(desc);
		desc = NULL;
	}
	if (!min_a)
	{
		free(min_a);
		min_a = NULL;
	}
	if (!min_b)
	{
		free(min_b);
		min_b = NULL;
	}
}

void	ft_error(t_info *desc, int *min_a, int *min_b)
{
	ft_putendl_fd("Error", 2);
	if (desc)
		ft_free_all(desc, min_a, min_b);
	exit (EXIT_FAILURE);
}
