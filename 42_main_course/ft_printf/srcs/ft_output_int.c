/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:09:22 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 11:11:46 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_write_zero_point(t_print *tab)
{
	if (tab->prc < 0)
		tab->len += write(1, "0", 1);
	if (!tab->width && tab->prc-- > 0)
		tab->len += write(1, "0", 1);
}

void	ft_write_zero(t_print *tab)
{
	tab->is_zero = 1;
	if ((tab->width && tab-> zero) || tab->pnt)
	{
		ft_right_zero(tab);
		return ;
	}
	ft_update_tab(tab, 1);
	while (!tab->minus && --tab->width > 0)
		tab->len += write(1, " ", 1);
	tab->len += write(1, "0", 1);
	while (tab->minus && --tab->width > 0)
		tab->len += write(1, " ", 1);
}

void	ft_output_int(t_print *tab)
{
	int		i;
	int		j;
	int		len;
	char	*num;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	if (j < 0)
		j = ft_check_sign(tab, j);
	num = ft_itoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while (num[i])
		tab->len += write(1, &num[i++], 1);
	ft_left_idupx(tab);
	free(num);
}

void	ft_output_unsigned_int(t_print *tab)
{
	int				i;
	unsigned int	j;
	int				len;
	char			*num;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	num = ft_uitoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while (num[i])
		tab->len += write(1, &num[i++], 1);
	ft_left_idupx(tab);
	free(num);
}
