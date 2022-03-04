/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:24 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 10:54:42 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		res;

	if (!format)
		return (0);
	res = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_set_tab(tab);
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
