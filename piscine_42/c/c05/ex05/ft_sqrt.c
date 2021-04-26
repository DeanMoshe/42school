/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:23:41 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/24 14:54:42 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		if (i * i == (nb / 2 + 1))
			return (i);
		i++;
	}
	return (0);
}

int main()
{
	printf("-3 = %d\n", ft_sqrt(-3));
	printf("3 = %d\n", ft_sqrt(3));
	printf("0 = %d\n", ft_sqrt(0));
	printf("1 = %d\n", ft_sqrt(1));
	printf("-1 = %d\n", ft_sqrt(-1));
	printf("2147483647 = %d\n", ft_sqrt(2147483647));
	printf("-2147483648 = %d\n", ft_sqrt(-2147483648));
}
