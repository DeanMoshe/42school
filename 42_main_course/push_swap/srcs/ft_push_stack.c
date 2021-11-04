/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:24:29 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/20 19:56:22 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_other_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*elem;

	if (ft_stack_is_empty(stack_a))
		return ;
	elem = stack_a->first;
	if (ft_stack_length(stack_a) && ft_stack_length(stack_b))
	{
		stack_a->first = stack_a->first->next;
		elem->next = stack_b->first;
		stack_b->first = elem;
	}
	else if (!(ft_stack_length(stack_b)) && ft_stack_length(stack_a))
	{
		stack_a->first = stack_a->first->next;
		elem->next = NULL;
		stack_b->first = elem;
	}
}

void	ft_push_end_plus_origin(t_stack *stack, int num, \
								t_elem *origin, t_info *desc)
{
	t_elem	*elem;
	t_elem	*tmp;

	elem = (t_elem *)malloc(sizeof(t_elem));
	if (!elem)
		ft_error(desc, NULL, NULL);
	elem->value = num;
	elem->curr = origin;
	if (elem == NULL)
		exit(EXIT_FAILURE);
	if (!stack->first)
	{
		elem->next = NULL;
		stack->first = elem;
		return ;
	}
	tmp = stack->first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}

void	ft_push_end(t_info *desc, int num)
{
	t_elem	*elem;
	t_elem	*tmp;

	elem = (t_elem *)malloc(sizeof(t_elem));
	if (!elem)
		ft_error(desc, NULL, NULL);
	elem->value = num;
	if (elem == NULL)
		exit(EXIT_FAILURE);
	if (!desc->stack_a->first)
	{
		elem->next = NULL;
		desc->stack_a->first = elem;
		return ;
	}
	tmp = desc->stack_a->first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}

void	pa(t_stack *first, t_stack *second, t_info *desc)
{
	if (ft_stack_is_empty(first))
		return ;
	ft_push_other_stack(first, second);
	ft_putendl_fd("pa", 1);
	desc->counter++;
}

void	pb(t_stack *first, t_stack *second, t_info *desc)
{
	if (ft_stack_is_empty(first))
		return ;
	ft_push_other_stack(first, second);
	ft_putendl_fd("pb", 1);
	desc->counter++;
}
