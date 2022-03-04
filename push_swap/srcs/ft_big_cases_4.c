/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_cases_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:28:09 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:24 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	ft_sort_mins(t_info *desc, t_param *params)
{
	while (params->min_b > 0 && params->min_a > 0)
	{
		rr(desc->stack_a, desc->stack_b, 1, desc);
		params->min_b--;
		params->min_a--;
	}
	while (params->min_b < 0 && params->min_a < 0)
	{
		rrr(desc->stack_a, desc->stack_b, 1, desc);
		params->min_b++;
		params->min_a++;
	}
}

void	ft_sort(t_info *desc, t_param *params)
{
	if ((params->min_b > 0 && params->min_a > 0)
		|| (params->min_b < 0 && params->min_a < 0))
		ft_sort_mins (desc, params);
	while (params->min_b > 0)
	{
		rb(desc->stack_b, 1, desc);
		(params->min_b)--;
	}
	while (params->min_b < 0)
	{
		rrb(desc->stack_b, 1, desc);
		params->min_b++;
	}
	while (params->min_a > 0)
	{
		ra(desc->stack_a, 1, desc);
		(params->min_a)--;
	}
	while (params->min_a < 0)
	{
		rra(desc->stack_a, 1, desc);
		params->min_a++;
	}
	pa(desc->stack_b, desc->stack_a, 1, desc);
}
