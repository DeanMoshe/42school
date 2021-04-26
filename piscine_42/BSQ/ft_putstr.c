/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:17:11 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/08 15:17:22 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str, int out)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(out, &str[i], 1);
		i++;
	}
}

void	ft_put_arr(char **str)
{
	int i;

	i = 0;
	while (*str)
	{
		ft_putstr(str[i], 1);
		i++;
		str++;
	}
}
