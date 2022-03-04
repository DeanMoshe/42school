/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:05:46 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:28:11 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	t_elem	*prev;
	t_elem	*elem;

	if (!stack->first || !stack->first->next || !stack)
		return ;
	elem = stack->first;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = stack->first;
	stack->first = elem;
	prev->next = NULL;
}

void	rra(t_stack *stack_a, int print_op, t_info *desc)
{
	ft_reverse_rotate(stack_a);
	if (print_op == 1)
		ft_putendl_fd("rra", 1);
	desc->counter++;
}

void	rrb(t_stack *stack_b, int print_op, t_info *desc)
{
	ft_reverse_rotate(stack_b);
	if (print_op == 1)
		ft_putendl_fd("rrb", 1);
	desc->counter++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print_op, t_info *desc)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (print_op == 1)
		ft_putendl_fd("rrr", 1);
	desc->counter--;
}
