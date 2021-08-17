/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:25:29 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 14:46:55 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_zero_flag(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	pos++;
	tab->zero = 1;
	while (format[pos] == '0')
		pos++;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab->width = i;
	return (pos);
}

int	ft_precision_flag(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	pos++;
	tab->pnt = 1;
	if (ft_isalpha(format[pos]) || format[pos] == '%')
		ft_check_precision(tab);
	while (format[pos] == '0' || ft_check_flag(format[pos]))
	{
		pos++;
		ft_check_precision(tab);
	}
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab->prc = i;
	if (format[pos] == '*')
		pos = ft_asterisk_flag(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return (pos);
}

int	ft_minus_flag(t_print *tab, const char *format, int pos)
{
	pos++;
	if (tab->minus == 1)
	{
		while (format[pos] == '-' || format[pos] == '0')
			pos++;
		return (pos);
	}
	tab->minus = 1;
	tab->zero = 0;
	while (format[pos] == '-' || format[pos] == '0')
		pos++;
	pos = ft_width_flag(tab, format, pos);
	return (pos);
}

int	ft_asterisk_flag(t_print *tab, const char *format, int pos)
{
	pos++;
	if (!tab->pnt)
	{
		tab->width = va_arg(tab->args, int);
		ft_check_width(tab);
	}
	else
	{
		tab->prc = va_arg(tab->args, int);
		ft_check_precision(tab);
	}
	if (format[pos] == '.')
		pos = ft_precision_flag(tab, format, pos);
	if (format[pos] == '*')
		pos = ft_asterisk_flag(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return (pos);
}

int	ft_width_flag(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab->width = i;
	if (format[pos] == '.')
		pos = ft_precision_flag(tab, format, pos);
	return (pos);
}
