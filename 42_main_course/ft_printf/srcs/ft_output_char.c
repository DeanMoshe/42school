/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:27:30 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/17 15:20:28 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	ft_update_tab(tab, 1);
	if (tab->width && !tab->minus)
		ft_right_align(tab, 0);
	tab->len += write(1, &a, 1);
	if (tab->width && tab->minus)
		ft_left_align(tab, 0);
}
