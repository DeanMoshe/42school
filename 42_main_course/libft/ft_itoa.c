/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:01:40 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/28 20:01:40 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	long		nbr;

	nbr = n;
	len = ft_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
