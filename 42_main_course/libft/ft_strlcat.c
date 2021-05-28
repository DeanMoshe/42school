/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:33:26 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/23 13:33:26 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size - 1 < dst_len)
		return (src_len + size);
	if (size - 1 > dst_len)
	{
		while (src[i] && dst_len + i < size - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
