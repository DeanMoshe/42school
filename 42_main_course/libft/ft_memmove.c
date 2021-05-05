/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:00:01 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/24 18:00:01 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;

	if (!dest || !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	if (dest_ptr > src_ptr)
	{
		while (n--)
			dest_ptr[n - 1] = src_ptr[n - 1];
	}
	else
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	return (dest);
}
