/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_cases_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:36:45 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/20 19:55:47 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_target_index(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->first;
	while (elem)
	{
		elem->curr->t_i = elem->t_i;
		elem = elem->next;
	}
}

void	ft_set_target_index_cpy(t_stack *cpy)
{
	t_elem	*elem;
	int		i;

	elem = cpy->first;
	i = 0;
	while (elem)
	{
		elem->t_i = i;
		elem = elem->next;
		i++;
	}
}

void	ft_bubble_swap(t_elem **origin, t_elem **tmplist, \
						t_elem **elem, int *tmp)
{
	*tmp = (*elem)->value;
	*origin = (*elem)->curr;
	(*elem)->value = (*tmplist)->value;
	(*elem)->curr = (*tmplist)->curr;
	(*tmplist)->value = (*tmp);
	(*tmplist)->curr = *origin;
}

void	ft_bubble_sort(t_stack *stack_cpy)
{
	int		tmp;
	t_elem	*origin;
	t_elem	*tmplist;
	t_elem	*elem;

	tmplist = stack_cpy->first;
	elem = stack_cpy->first;
	origin = stack_cpy->first->curr;
	tmp = stack_cpy->first->value;
	while (elem)
	{
		while (tmplist)
		{
			if (elem->value > tmplist->value)
				ft_bubble_swap(&origin, &tmplist, &elem, &tmp);
			tmplist = tmplist->next;
		}
		elem = elem->next;
		tmplist = elem;
	}
}

t_stack	*ft_stack_cpy(t_stack *stack, t_info *desc, t_param *params)
{
	t_stack	*cpy;
	t_elem	*elem;

	if (!stack)
		return (NULL);
	cpy = (t_stack *)malloc(sizeof(t_stack));
	if (!cpy)
		ft_error(desc, &params->min_a, &params->min_b);
	elem = stack->first;
	cpy->first = NULL;
	while (elem)
	{
		ft_push_end_plus_origin(cpy, elem->value, elem, desc);
		elem = elem->next;
	}
	return (cpy);
}
