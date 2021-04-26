/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:39:30 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/18 23:50:34 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a++ <= '7')
	{
		b = a;
		while (b++ <= '8')
		{
			c = b;
			while (c++ < '9')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (!(a == '7' && b == '8' && c == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
