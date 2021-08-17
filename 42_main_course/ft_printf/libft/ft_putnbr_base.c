/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:29:02 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/17 16:33:25 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int				i;
	unsigned long	num;
	unsigned long	base_len;

	i = 1;
	num = n;
	base_len = ft_strlen(base);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (i);
	}
	if (num >= base_len)
	{
		i += ft_putnbr_base(num / base_len, base);
		ft_putchar_fd(base[num % base_len], 1);
	}
	else if (num < base_len)
		ft_putchar_fd(base[num], 1);
	return (i);
}
