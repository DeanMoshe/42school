/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:39:47 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/28 18:40:35 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strcpy(char *dest, char *src, char sep, int mark, int j)
{
	dest[mark] = sep;
	mark++;
	while (mark <= j + 1)
	{
		dest[mark] = src[mark];
		mark++;
	}
	dest[mark] = sep;
	dest[mark + 1] = '\0';
	return (dest);
}

int					ft_strlen(char *str)
{
	int			len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char				*ft_strcmp(char *res, char *s1, char *s2)
{
	int i;
	int j;
	int k;
	int mark;

	i = 0;
	k = 0;
	j = 0;
	mark = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return (0);
	else
	{
		while (s2[i] != '\0')
		{
			while (s1[j] != '\0')
			{
				if (s1[j] == s2[i])
				{
					res[k] = (char *)malloc(sizeof(s1) * (ft_strlen(s1[j]) + s2[i] * 2 + 1));
					if (NULL == res[k])
						return (0);
					res[k] = ft_strcpy(res[k], s1, s2[i], mark, j);
					mark = j + 1;
					i++;
					k++;
				}
				j++;
			}
			i++;

		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char		**res;
	int				i;

	res = 0;
	ft_strcmp(res, str, charset);
	if (NULL == res)
		return (NULL);
	return (res);
}