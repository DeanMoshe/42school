/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:46:09 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/17 15:20:07 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_write_pnt(t_print *tab)
{
	ft_update_tab_string(tab, NULL, 0);
	while (tab->width--)
		tab->len += write(1, " ", 1);
}

void	ft_output_string(t_print *tab)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	s = va_arg(tab->args, char *);
	if (!s)
		s = "(null)";
	if (s && tab->pnt == 1 && tab->prc == 0)
		return (ft_write_pnt(tab));
	len = ft_update_tab_string(tab, s, len);
	if (!tab->minus && tab->width > len)
		ft_right_align(tab, len);
	if (tab->prc > 0)
		while (s[i] && tab->prc--)
			tab->len += write(1, &s[i++], 1);
	else
		while (s[i])
			tab->len += write(1, &s[i++], 1);
	if (s && tab->minus && tab->width)
		ft_left_align(tab, len);
}
