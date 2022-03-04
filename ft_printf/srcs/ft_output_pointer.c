/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:19:00 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 11:04:32 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_write_null_ptr(t_print *tab)
{
	if (tab->width > tab->prc)
	{
		while (tab->width-- > (tab->prc + 2))
			tab->len += write(1, " ", 1);
	}
	tab->len += write(1, "0x", 2);
	while (tab->prc-- > 0)
		tab->len += write(1, "0", 1);
}

void	ft_output_pointer(t_print *tab)
{
	int				i;
	unsigned long	j;

	i = 2;
	j = va_arg(tab->args, unsigned long);
	if (!j && tab->pnt && tab->prc > 0)
	{
		ft_write_null_ptr(tab);
		return ;
	}
	if (!(!j && tab->pnt))
		i += ft_numlen_base(j, 16);
	if (!tab->prc || tab->width > tab->prc)
	{
		ft_update_tab(tab, i);
		ft_right_idupx(tab);
	}
	else
		tab->prc = tab->prc + 2 - i;
	tab->len += write(1, "0x", 2);
	while (tab->prc-- > 0)
		tab->len += write(1, "0", 1);
	if (!(!j && tab->pnt))
		tab->len += ft_putnbr_base(j, "0123456789abcdef");
	ft_left_idupx(tab);
}
