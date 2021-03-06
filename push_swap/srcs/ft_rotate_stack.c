/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:04:53 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:06 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ra(t_stack *stack_a, int print_op, t_info *desc)
{
	if (!stack_a || !desc)
		return ;
	ft_rotate_stack(stack_a);
	if (print_op == 1)
		ft_putendl_fd("ra", 1);
	desc->counter++;
}

void	rb(t_stack *stack_b, int print_op, t_info *desc)
{
	if (!stack_b || !desc)
		return ;
	ft_rotate_stack(stack_b);
	if (print_op == 1)
		ft_putendl_fd("rb", 1);
	desc->counter++;
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print_op, t_info *desc)
{
	if (!stack_a || !stack_b || !desc)
		return ;
	ft_rotate_stack(stack_a);
	ft_rotate_stack(stack_b);
	if (print_op == 1)
		ft_putendl_fd("rr", 1);
	desc->counter++;
}
