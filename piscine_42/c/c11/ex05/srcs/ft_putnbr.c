/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:05:25 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/02 20:05:56 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(long long nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb >= 0)
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putchar((nb % 10) + '0');
		}
		else
			ft_putchar(nb + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
}
