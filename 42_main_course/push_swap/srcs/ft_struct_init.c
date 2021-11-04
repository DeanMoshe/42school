/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:15:56 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/20 19:57:09 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_desc_init(void)
{
	t_info		*desc;
	t_stack		*stack_a;
	t_stack		*stack_b;

	desc = (t_info *)malloc(sizeof(t_info));
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!desc || !stack_a || !stack_b)
		ft_error(desc, NULL, NULL);
	stack_a->first = NULL;
	stack_b->first = NULL;
	desc->counter = 0;
	desc->stack_a = stack_a;
	desc->stack_b = stack_b;
	return (desc);
}

t_param	ft_init_params(t_info *desc)
{
	t_param	params;

	params.counter_a = 0;
	params.counter_b = 0;
	params.elem = desc->stack_b->first;
	params.best = NULL;
	params.min_a = 0;
	params.min_b = 0;
	params.min_move = 0xFFFFFFF;
	params.action_b = 0;
	params.total = 0;
	return (params);
}

void	ft_init_variables(int *i, int *pos, bool *end)
{
	*i = 1;
	*pos = 0;
	*end = false;
}
