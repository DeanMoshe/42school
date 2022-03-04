/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:56:35 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:27:55 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_biggest(t_stack *stack)
{
	int		big;
	t_elem	*elem;

	if (!stack)
		return (0);
	elem = stack->first;
	big = elem->value;
	while (elem)
	{
		if (elem->value > big)
			big = elem->value;
		elem = elem->next;
	}
	return (big);
}

int	ft_find_smallest(t_stack *stack)
{
	int		small;
	t_elem	*elem;

	if (!stack)
		return (0);
	elem = stack->first;
	small = elem->value;
	while (elem)
	{
		if (elem->value < small)
			small = elem->value;
		elem = elem->next;
	}
	return (small);
}

int	ft_is_on_top(t_stack *stack, int num)
{
	if (stack->first->value == num)
		return (1);
	return (0);
}

void	ft_bring_to_top(t_stack *stack, int num, t_info *desc)
{
	if (!stack)
		return ;
	if (ft_is_on_top(stack, num))
		return ;
	if (ft_binary_search(stack, num) == 1)
	{
		while (!ft_is_on_top(stack, num))
			ra(stack, 1, desc);
	}
	else
	{
		while (!ft_is_on_top(stack, num))
			rra(stack, 1, desc);
	}
}

int	ft_binary_search(t_stack *stack, int num)
{
	t_elem		*elem;
	float		i;

	if (!stack)
		return (0);
	elem = stack->first;
	i = 1;
	while (elem)
	{
		if (elem->value == num)
		{
			if (i / (float)ft_stack_length(stack) <= 0.5)
				return (1);
			else
				return (2);
		}
		elem = elem->next;
		i++;
	}
	return (0);
}
