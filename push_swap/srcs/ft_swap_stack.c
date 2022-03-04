/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:05:53 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:27:18 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_ab(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*second;

	if (!stack)
		return ;
	if (ft_stack_length(stack) >= 2)
	{
		elem = stack->first;
		second = stack->first->next->next;
		stack->first = stack->first->next;
		stack->first->next = elem;
		elem->next = second;
	}
}

void	sa(t_stack *stack_a, int print_op, t_info *desc)
{
	if (!stack_a || !desc)
		return ;
	ft_swap_ab(stack_a);
	if (print_op == 1)
		ft_putendl_fd("sa", 1);
	desc->counter++;
}

void	sb(t_stack *stack_b, int print_op, t_info *desc)
{
	if (!stack_b || !desc)
		return ;
	ft_swap_ab(stack_b);
	if (print_op == 1)
		ft_putendl_fd("sb", 1);
	desc->counter++;
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print_op, t_info *desc)
{
	if (!stack_a || !stack_b || !desc)
		return ;
	ft_swap_ab(stack_a);
	ft_swap_ab(stack_b);
	if (print_op == 1)
		ft_putendl_fd("ss", 1);
	desc->counter++;
}
