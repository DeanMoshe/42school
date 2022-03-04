/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_cases_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:56:48 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:28 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_opt_actions(int count_a, int count_b)
{
	if (count_a > 0 && count_b > 0)
		return (ft_abs_value(count_a) + ft_abs_value(count_b) \
		- ft_min(count_a, count_b));
	else if (count_a < 0 && count_b < 0)
		return (ft_abs_value(count_a) + ft_abs_value(count_b) \
		+ ft_max(count_a, count_b));
	else
		return (ft_abs_value(count_a) + ft_abs_value(count_b));
	return (1);
}

int	ft_find_ins(t_stack *stack, int num, t_elem *tmp, t_elem *prev)
{
	int		i;
	int		pos;
	bool	end;

	ft_init_variables(&i, &pos, &end);
	while (prev && !end)
	{
		if (tmp == NULL)
		{
			tmp = stack->first;
			end = true;
		}
		if ((num > prev->t_i && num < tmp->t_i)
			|| (prev->t_i > tmp->t_i && (num < tmp->t_i || num > prev->t_i)))
			pos = i;
		i++;
		prev = tmp;
		tmp = tmp->next;
	}
	if (pos > ft_stack_length(stack) / 2)
		pos -= ft_stack_length(stack);
	return (pos);
}

t_elem	*ft_eval_actions(t_info *desc, t_param *par)
{
	t_elem	*tmp;
	t_elem	*prev;

	par->counter_b = 0;
	par->min_move = 0xFFFFFFF;
	while (par->elem)
	{
		tmp = desc->stack_a->first->next;
		prev = desc->stack_a->first;
		par->counter_a = ft_find_ins(desc->stack_a, par->elem->t_i, tmp, prev);
		par->action_b = par->counter_b;
		if (par->counter_b > ft_stack_length(desc->stack_b) / 2)
			par->action_b -= ft_stack_length(desc->stack_b);
		par->total = ft_opt_actions(par->counter_a, par->action_b);
		if (par->total < par->min_move)
		{
			par->min_move = par->total;
			par->best = par->elem;
			par->min_a = par->counter_a;
			par->min_b = par->action_b;
		}
		par->elem = par->elem->next;
		par->counter_b++;
	}
	return (par->best);
}

int	ft_abs_value(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
