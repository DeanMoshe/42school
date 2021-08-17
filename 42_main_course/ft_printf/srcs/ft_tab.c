/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:10:34 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 10:48:27 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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
	else if (tab->prc > tab->width)
	{
		tab->width = 0;
		tab->prc -= len;
	}
}

int	ft_update_tab_string(t_print *tab, char *s, int len)
{
	if (s)
		len = ft_strlen(s);
	if (tab->prc > 0 && len > tab->prc)
		len = tab->prc;
	return (len);
}
