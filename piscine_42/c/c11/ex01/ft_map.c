/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:39 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/02 15:01:43 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int i;
	int *res;

	i = 0;
	if (tab != (void*)0)
	{
		res = (int*)malloc(sizeof(int) * length);
		if (NULL == res)
			return (0);
		while (i < length)
		{
			res[i] = f(tab[i]);
			i++;
		}
		return (res);
	}
	return (0);
}
