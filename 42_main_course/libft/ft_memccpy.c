/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:51:40 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/24 17:51:40 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;

	i = 0;
	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
