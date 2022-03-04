/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:07:09 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:00 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_info *desc)
{
	t_elem	*elem;

	elem = desc->stack_a->first;
	if (elem->value > elem->next->value)
		sa(desc->stack_a, 1, desc);
}

void	ft_sort_three(t_info *desc)
{
	int	first;
	int	second;
	int	third;

	first = desc->stack_a->first->value;
	second = desc->stack_a->first->next->value;
	third = desc->stack_a->first->next->next->value;
	if (first > second && second < third && first < third)
		sa(desc->stack_a, 1, desc);
	else if (first > second && second > third && first > third)
	{
		sa(desc->stack_a, 1, desc);
		rra(desc->stack_a, 1, desc);
	}
	else if (first > second && second < third && first > third)
		ra(desc->stack_a, 1, desc);
	else if (first < second && second > third && first < third)
	{
		sa(desc->stack_a, 1, desc);
		ra(desc->stack_a, 1, desc);
	}
	else if (first < second && second > third && first > third)
		rra(desc->stack_a, 1, desc);
}

void	ft_prepare_stack(t_stack *stack_a, t_stack *stack_b, t_info *desc)
{
	int	small;
	int	big;

	big = ft_find_biggest(stack_a);
	small = ft_find_smallest(stack_a);
	while (!ft_is_on_top(stack_a, small))
		ft_bring_to_top(stack_a, small, desc);
	pb(stack_a, stack_b, 1, desc);
	if (ft_stack_length(stack_a) > 3)
	{
		while (!ft_is_on_top(stack_a, big))
			ft_bring_to_top(stack_a, big, desc);
		pb(stack_a, stack_b, 1, desc);
	}
}

void	ft_sort_four_five(t_info *desc)
{
	int	stack_len;

	stack_len = ft_stack_length(desc->stack_a);
	ft_prepare_stack(desc->stack_a, desc->stack_b, desc);
	ft_sort_three(desc);
	if (stack_len == 5)
	{
		pa(desc->stack_a, desc->stack_b, 1, desc);
		ra(desc->stack_a, 1, desc);
	}
	pa(desc->stack_a, desc->stack_b, 1, desc);
	if (ft_stack_is_empty(desc->stack_a) == 1)
		ft_error(desc, NULL, NULL);
}

void	ft_small_cases(t_info *desc)
{
	if (!desc->stack_a || !desc)
		ft_error(desc, NULL, NULL);
	if (ft_stack_length(desc->stack_a) == 2)
		ft_sort_two(desc);
	else if (ft_stack_length(desc->stack_a) == 3)
	{
		ft_sort_three(desc);
	}
	else if (ft_stack_length(desc->stack_a) > 3)
		ft_sort_four_five(desc);
	if (ft_stack_is_empty(desc->stack_a))
		ft_error(desc, NULL, NULL);
	ft_free_all(desc, NULL, NULL);
	exit (EXIT_SUCCESS);
}
