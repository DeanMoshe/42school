/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:03:37 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/08 14:25:28 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_length(t_stack *stack)
{
	int		len;
	t_elem	*elem;

	len = 0;
	elem = stack->first;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}

int	ft_stack_is_empty(t_stack *stack)
{
	if (stack->first == NULL)
		return (1);
	return (0);
}

int	ft_stack_is_sorted(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->first;
	if (!elem)
		return (0);
	while (elem->next)
	{
		if (elem->next->value < elem->value)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long	ft_push_atoi(char *str, t_info *desc)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!str[i] || !ft_isdigit(str[i]))
		ft_error(desc, NULL, NULL);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			ft_error(desc, NULL, NULL);
	}
	if (str[i] && !(ft_isdigit(str[i])) && str[i] != ' ')
		ft_error(desc, NULL, NULL);
	return (res * sign);
}
