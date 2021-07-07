/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:59:33 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/07 19:05:25 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_check_precision(t_print *tab)
{
	if (tab->prc == 0 && tab->zero == 1)
	{
		tab->zero = 0;
		tab->perc = 1;
	}
	if (tab->prc < 0)
	{
		tab->prc = 0;
		tab->pnt = 0;
	}
}

void	ft_check_width(t_print *tab)
{
	if (tab->width < 0)
	{
		tab->width *= -1;
		tab->minus = 1;
		tab->zero = 0;
	}
}

int	ft_check_sign(t_print *tab, int i)
{
	tab->sign = 1;
	tab->space = 0;
	return (i * -1);
}

int	ft_check_flag(char c)
{
	if (c == '.' || c =='-')
		return (1);
	return (0);
}	
