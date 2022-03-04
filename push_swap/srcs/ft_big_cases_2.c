/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_cases_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:37:15 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:34 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_largest_keep_a(t_elem *start, t_stack *stack, bool define)
{
	t_elem	*elem;
	int		max_index;
	int		counter;

	elem = start;
	max_index = 0;
	counter = 0;
	while (elem)
	{
		if (elem->t_i >= max_index)
		{
			if (define)
				elem->keep = true;
			max_index = elem->t_i;
			++counter;
		}
		else if (define)
			elem->keep = false;
		elem = elem->next;
		if (elem == NULL)
			elem = stack->first;
		if (elem == start)
			break ;
	}
	return (counter);
}

t_elem	*ft_get_max_keep(t_stack *stack)
{
	t_elem		*elem;
	t_elem		*max;
	int			max_keep;
	int			cur;

	max_keep = 0;
	elem = stack->first;
	while (elem)
	{
		cur = ft_largest_keep_a(elem, stack, false);
		if (cur > max_keep)
		{
			max_keep = cur;
			max = elem;
		}
		elem = elem->next;
	}
	return (max);
}

void	ft_set_keep(t_info *desc)
{
	t_elem		*max;
	t_stack		*stack;

	stack = desc->stack_a;
	max = ft_get_max_keep(stack);
	desc->max_size = ft_largest_keep_a(max, stack, true);
}

void	ft_push_keep_false(t_info *desc)
{
	int	size;

	size = ft_stack_length(desc->stack_a) - desc->max_size;
	while (size > 0)
	{
		if (desc->stack_a->first->keep == false)
		{
			pb(desc->stack_a, desc->stack_b, 1, desc);
			size--;
		}
		else
			ra(desc->stack_a, 1, desc);
	}
}
