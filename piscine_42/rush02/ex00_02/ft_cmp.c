/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:03:50 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/07 16:03:53 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void ft_conditions (char **res, char *buf, int k, char *dict)
{
	// char *dig[3];

	// dig[0] = buf[1];
	// dig[1] = buf[2];
	// dig[2] = "\0";
	if (buf[1] == '1')
	{
		res[0] = ft_search("1", dict);
		res[1] = ft_search("12", dict);
		res[2] = ft_search("12", dict);
		res[3] = ft_search(ft_recursive_power(k), dict);
		res[4] = "\0";
	}
	else
	{
		res[0] = ft_search("2", dict);
		res[1] = ft_search("100", dict);
		res[2] = ft_search("30", dict); 
		res[3] = ft_search("3", dict);
		res[4] = ft_search(ft_recursive_power(k), dict);
		res[5] = "\0";
	}
	ft_putarr(res);
}

void ft_cmp (char *str, char *dict)
{
	int				len;
	int				i;
	int				k;
	char			**res;
	char			str1[4];
	char			*buf = str1;

	i = 0;
	k = 1;
	len = ft_strlen(str);
	res = (char**)malloc(sizeof(char**) * 1000);
	res[0] = malloc(sizeof(char*) * 1000);
	res[1] = malloc(sizeof(char*) * 1000);
	res[2] = malloc(sizeof(char*) * 1000);
	res[3] = malloc(sizeof(char*) * 1000);
	res[4] = malloc(sizeof(char*) * 1000);
	res[5] = malloc(sizeof(char*) * 1000);
	if (res == NULL)
		return ;
	if (len == 1 && str[0] == '0')
		ft_putstr(ft_search("0", dict), 1);
	while (len > 0)
	{
		while (k < 3 && k <= len)
		{
			if (str[len - k] > 48 && str[len - k] < 58)
				buf[k - 1] = str[len - k];
			else
				buf[k - 1] = 'x';
			k++;
		}
		len -= 3;
		buf[3] = '\0';
		ft_conditions(res, buf, i, dict);
		i++;
	}
}
