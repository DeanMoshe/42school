/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:53:44 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/27 22:43:38 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int					ft_strlen(char *str)
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

char				*ft_strdup(char *src)
{
	char *dest;

	dest = (char *)malloc(sizeof(src) * ft_strlen(src) + 1);
	if (NULL == dest)
		return (0);
	dest = ft_strcpy(dest, src);
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*res;
	int				i;

	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (NULL == res)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		res[i].size = ft_strlen(av[i]);
		i++;
	}
	res[i].str = 0;
	return (res);
}
