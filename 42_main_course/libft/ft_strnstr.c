/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:55:12 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/24 10:55:12 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0 || big == little)
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0' && \
				big[i + j] == little[j] && i + j < len)
			j++;
		if (j == little_len)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
