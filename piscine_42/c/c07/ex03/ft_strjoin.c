/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:03:54 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/25 19:05:21 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}



char	*ft_strcat(char *res, char *src, char *sep)
{
	int	i;
	int	l;

	i = 0;
	if (res[0] == '\0')
	{
		res = src;
		return (res);
	}
	else 
		l = ft_strlen(res);
	while ()
	{
		res[l] = sep;
	}
	
	l += 1;
	while (src[i] != '\0')
	{
		res[l + i] = src[i];
		i++;
	}
	res[l + i] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	char *res;
	int len;

	i = 0;
	len = 0;
	res = 0;
	if (size == 0)
		free(strs);
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	res = (char *)malloc(sizeof(res) * len + 1);
	if (NULL == res)
		return (0);
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, strs[i], sep);
		i++;
	}
	return (res);
}
