/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:19:49 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/25 15:19:49 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if ((size_t)start > s_len)
		return (ft_strdup(""));
	if (len <= (s_len - start))
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * ((s_len - start) + 1));
	if (!str)
		return (NULL);
	while ((start + i) < s_len && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
