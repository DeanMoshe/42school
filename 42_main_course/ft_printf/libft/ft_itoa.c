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

char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	long		nbr;

	nbr = n;
	len = ft_numlen(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (n < 0 && n != INT_MIN)
		res[0] = '-';
	return (res);
}
