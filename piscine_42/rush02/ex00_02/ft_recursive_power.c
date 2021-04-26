/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:25:37 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/23 18:58:16 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_recursive_power(int power)
{
	char *str;
	int i;

	str = malloc(sizeof(char) * 37);
	if (str == NULL)
		return (NULL);
	i = 1;
	while (power > 0)
	{
		str[i] = '0';
		i++;
		str[i] = '0';
		i++;
		str[i] = '0';
		i++;
		power--;
	}
	str[0] = '1';
	str[i] = '\0';
	return (str);
}
