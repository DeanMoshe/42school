/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexa_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:02:29 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/07 19:14:08 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_output_hexa_int(t_print *tab, int c)
{
	int				len;
	unsigned int	j;
	char			*num;

	j = va_arg(tab->args, unsigned int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while (num && len-- > 0)
		tab->len += write(1, &num[len], 1);
	ft_left_idupx(tab);
	free(num);
}
