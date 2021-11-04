/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:04:53 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/20 19:56:34 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_last_elem(t_stack *stack)
{
	t_elem	*elem;

	if (!stack || !stack->first)
		return (NULL);
	elem = stack->first;
	while (elem->next)
		elem = elem->next;
	return (elem);
}

void	ft_rotate_stack(t_stack *stack)
{
	t_elem	*last;
	t_elem	*tmp;

	if (!stack || !stack->first)
		return ;
	last = ft_last_elem(stack);
	tmp = stack->first;
	stack->first = stack->first->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack *stack_a, t_info *desc)
{
	if (!stack_a || !desc)
		return ;
	ft_rotate_stack(stack_a);
	ft_putendl_fd("ra", 1);
	desc->counter++;
}

void	rb(t_stack *stack_b, t_info *desc)
{
	if (!stack_b || !desc)
		return ;
	ft_rotate_stack(stack_b);
	ft_putendl_fd("rb", 1);
	desc->counter++;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_info *desc)
{
	if (!stack_a || !stack_b || !desc)
		return ;
	ft_rotate_stack(stack_a);
	ft_rotate_stack(stack_b);
	ft_putendl_fd("rr", 1);
	desc->counter++;
}
