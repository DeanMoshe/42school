/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:56:03 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/17 15:20:29 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_get_type(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_output_char(tab);
	else if (format[pos] == 's')
		ft_output_string(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_output_int(tab);
	else if (format[pos] == 'u')
		ft_output_unsigned_int(tab);
	else if (format[pos] == 'p')
		ft_output_pointer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		ft_output_hexa_int(tab, format[pos] - 23);
	else if (format[pos] == '%')
		ft_output_percent(tab);
	return (pos);
}

int	ft_get_flag(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos]) || format[pos] == '%'))
	{
		if (format[pos] == ' ')
			pos = ft_space_flag(tab, pos);
		if (format[pos] == '0')
			pos = ft_zero_flag(tab, format, pos);
		if (format[pos] == '*')
			pos = ft_asterisk_flag(tab, format, pos);
		if (format[pos] == '-')
			pos = ft_minus_flag(tab, format, pos);
		if (format[pos] == '.')
			pos = ft_precision_flag(tab, format, pos);
		if (ft_isdigit(format[pos]))
			pos = ft_width_flag(tab, format, pos);
	}
	ft_get_type(tab, format, pos);
	ft_reset_tab(tab);
	return (pos);
}
