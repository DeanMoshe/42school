/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:36:48 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/27 21:45:34 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void ft_show_tab(struct s_stock_str *par)
{
	t_stock_str		*res;
	int				i;

	while (res)
	{
		write(1, &(res[i].size), 4);
		ft_putstr(res[i].str);
		ft_putstr(res[i].copy);
		i++;
	}
}
