/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:00:16 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/07 20:06:56 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int nbr)
{
	int			len;
	char		*res;

	len = ft_numlen(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nbr == 0)
		res[len] = '0';
	while (len > 0)
	{
		res[len--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (res);
}
