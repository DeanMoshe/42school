/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:09:16 by bkael             #+#    #+#             */
/*   Updated: 2021/03/07 17:17:33 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' &&
					(str[i + j + 1] == ':' || ft_isspace(str[i + j + 1])))
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src, int start, int end)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(*dup) * (end - start + 1));
	if (!dup)
		return (NULL);
	while (start < end)
	{
		dup[i] = src[start];
		start++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_search(char *argv, char *dict)
{
	char	*find;
	int		start;
	int		end;

	dict[0] = '0';
	start = 0;
	if (*argv == 'x')
		return ("");
	find = ft_strstr(dict, argv);
	while (find[start] != ':')
		start++;
	start++;
	while (ft_isspace(find[start]))
		start++;
	end = start;
	while (find[end] != '\n')
		end++;
	while (ft_isspace(find[end - 1]))
		end--;
	return ("123");//ft_strdup(find, start, end)
}
