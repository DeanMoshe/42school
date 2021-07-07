/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:36:29 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/07 18:26:08 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_output_percent(t_print *tab)
{
	if (tab->perc)
		tab->zero = 0;
	while (tab->zero && !tab->minus && --tab->width > 0)
		tab->len += write(1, "0", 1);
	while (!tab->minus && --tab->width > 0)
		tab->len += write(1, " ", 1);
	tab->len += write(1, "%", 1);
	while (tab->minus && --tab->width > 0)
		tab->len += write(1, " ", 1);
}
