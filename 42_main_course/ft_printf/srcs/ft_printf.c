/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:24 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/07 19:34:52 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_set_tab(t_print *tab)
{
	tab->width = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->minus = 0;
	tab->len = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->space = 0;
	return (tab);
}

t_print	*ft_reset_tab(t_print *tab)
{
	tab->width = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->minus = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->space = 0;
	return (tab);
}

void	ft_update_tab (t_print *tab, int len)
{
	if (tab->sign && tab->width)
		tab->width -= 1;
	if (tab->prc > 0)
		tab->zero = 0;
	if (tab->width && tab->width >= tab->prc)
	{
		if (tab->prc > len)
			tab->prc -= len;
		else
			tab->prc = 0;
		if (!tab->is_zero)
			tab->width = tab->width - tab->prc - len;
	}
	if (tab->width && tab->prc > tab->width)
	{
		tab->width = 0;
		tab->prc -= len;
	}
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		res;

	if (!format)
		return (0);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_set_tab(tab);
	res = 0;
	i = -1;
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_get_flag(tab, format, i + 1);
		else
			res += write(1, &format[i], 1);
	}
	res += tab->len;
	va_end(tab->args);
	free(tab);
	return (res);
}
