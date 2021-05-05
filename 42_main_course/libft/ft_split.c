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

static unsigned int			ft_getstrnb(char const *s, char c)
{
	unsigned int		i;
	unsigned int		str_nb;

	i = 0;
	str_nb = 0;
	if (s[0] != c)
		str_nb++;
	while (s[i])
	{
		if (s[i] && s[i] != c && s[i - 1] == c && i > 0)
			str_nb++;
		i++;
	}
	return (str_nb);
}

static	void				ft_getstr(char **buf, size_t *str_len, char c)
{
	while (**buf && **buf == c)
		(*buf)++;
	while (**buf && **buf != c)
	{
		str_len++;
		(*buf)++;
	}
}

static	char				**ft_freemem(char **res)
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

char						**ft_split(char const *s, char c)
{
	unsigned int		i;
	unsigned int		str_nb;
	size_t				str_len;
	char				**res;
	char				*buf;

	i = 0;
	str_len = 0;
	buf = (char *)s;
	if (!s)
		return (NULL);
	str_nb = ft_getstrnb(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (str_nb + 1))))
		return (NULL);
	while (i < str_nb)
	{
		ft_getstr(&buf, &str_len, c);
		if (!(res[i] = (char *)malloc(sizeof(char) * (str_len + 1))))
			return (ft_freemem(res));
		ft_strlcpy(res[i], buf, str_len);
		i++;
	}
	res[i] = '\0';
	return (res);
}
