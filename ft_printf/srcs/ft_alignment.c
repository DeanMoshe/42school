/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:15:38 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/17 15:20:33 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_right_idupx(t_print *tab)
{
	if (tab->space)
		tab->len += write(1, " ", 1);
	if (tab->sign && (tab->zero || tab->minus || (!tab->width && !tab->prc)))
	{
		tab->len += write(1, "-", 1);
		tab->sign = 0;
	}
	if (!tab->minus)
	{
		while (!tab->zero && --tab->width > -1)
			tab->len += write(1, " ", 1);
		while (tab->zero && --tab->width > -1)
			tab->len += write(1, "0", 1);
		if (tab->sign)
			tab->len += write(1, "-", 1);
	}
	while (--tab->prc > -1)
		tab->len += write(1, "0", 1);
}

void	ft_left_idupx(t_print *tab)
{
	if (tab->minus)
	{
		while (tab->minus && tab->zero && --tab->prc > -1)
			tab->len += write(1, "0", 1);
		while (tab->minus && --tab->width > -1)
			tab->len += write(1, " ", 1);
	}
}

void	ft_right_align(t_print *tab, int len)
{
	while (tab->zero && tab->width-- > len)
		tab->len += write(1, "0", 1);
	if (!tab->zero && tab->prc && tab->prc < len)
		while (tab->width-- > tab->prc)
			tab->len += write(1, " ", 1);
	else
		while (!tab->zero && tab->width-- > len)
			tab->len += write(1, " ", 1);
}

void	ft_left_align(t_print *tab, int len)
{
	while (tab->zero && tab->width-- > len)
		tab->len += write(1, "0", 1);
	while (!tab->zero && tab->width-- > len)
		tab->len += write(1, " ", 1);
}

void	ft_right_zero(t_print *tab)
{
	if (tab->width && (tab->pnt || tab->zero))
	{
		if (!tab->prc)
		{
			while (tab->zero && tab->width-- > 0)
				tab->len += write(1, "0", 1);
			while (!tab->zero && tab->width-- > 0)
				tab->len += write(1, " ", 1);
		}
		else
		{
			tab->width -= tab->prc;
			while (tab->minus && tab->prc-- > 0)
				tab->len += write(1, "0", 1);
			while (tab->width-- > 0)
				tab->len += write(1, " ", 1);
			while (!tab->minus && tab->prc-- > 0)
				tab->len += write(1, "0", 1);
		}
	}
	else if (tab->pnt)
		ft_write_zero_point(tab);
}
