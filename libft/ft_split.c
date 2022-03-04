/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:12:47 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/25 17:12:47 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freemem(char **res)
{
	unsigned int		i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static unsigned int	ft_getstrnb(char const *s, char c)
{
	unsigned int		i;
	unsigned int		str_nb;

	i = 0;
	str_nb = 0;
	if (s && s[0] != c)
		str_nb++;
	while (s[i])
	{
		if (s[i] && i > 0 && s[i] != c && s[i - 1] == c)
			str_nb++;
		i++;
	}
	return (str_nb);
}

static void	ft_getstr(char **buf, size_t *str_len, char c)
{
	int					i;

	i = 0;
	*buf = *buf + *str_len;
	*str_len = 0;
	while (**buf && **buf == c)
		(*buf)++;
	while ((*buf)[i] && (*buf)[i] != c)
	{
		(*str_len)++;
		i++;
	}
}

static char	**ft_split_str(char **res, unsigned int str_nb, \
							const char *s, char c)
{
	unsigned int		i;
	size_t				str_len;
	char				*buf;

	i = 0;
	str_len = 0;
	buf = (char *)s;
	while (i < str_nb)
	{
		ft_getstr(&buf, &str_len, c);
		res[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!res[i])
			return (ft_freemem(res));
		ft_strlcpy(res[i], buf, str_len + 1);
		i++;
	}
	res[i] = (void *)0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		str_nb;
	char				**res;

	if (!s || !*s)
	{
		res = malloc(sizeof(char *) * 1);
		if (!res)
			return (NULL);
		*res = (void *)0;
		return (res);
	}
	str_nb = ft_getstrnb(s, c);
	res = (char **)malloc(sizeof(char *) * (str_nb + 1));
	if (!res)
		return (NULL);
	ft_split_str(res, str_nb, s, c);
	return (res);
}
