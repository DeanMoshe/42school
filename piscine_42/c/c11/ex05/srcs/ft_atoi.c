/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 23:21:26 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/03 23:21:57 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoi(char *str)
{
	int			i;
	int			mark;
	long long	result;

	i = 0;
	result = 0;
	mark = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mark++;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + ((int)str[i] - 48);
		i++;
	}
	if (mark % 2 != 0)
		result = 0 - result;
	return (result);
}
