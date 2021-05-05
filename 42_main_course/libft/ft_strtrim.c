/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:27:08 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/25 16:27:08 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_inset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (0);
	}
	return (1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_inset(s1[start], set) == 0)
		start++;
	while (ft_inset(s1[end], set) == 0)
		end--;
	if (start == end)
		return (ft_strdup(""));
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
