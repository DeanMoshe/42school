/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:56:20 by bkael             #+#    #+#             */
/*   Updated: 2021/03/01 14:39:08 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putarr(char **str)
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