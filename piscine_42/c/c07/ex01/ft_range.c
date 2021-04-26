/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:06:02 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/26 21:44:37 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *res;

	i = 0;
	if (min >= max)
		return (0);
	res = malloc(sizeof(min) * (max - min));
	if (NULL == res)
		return (0);
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	return (res);
}
