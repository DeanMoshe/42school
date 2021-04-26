/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:15:35 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/26 21:45:43 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *res;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	res = malloc(sizeof(min) * (max - min));
	if (NULL == res)
		return (-1);
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	*range = res;
	return (i);
}
