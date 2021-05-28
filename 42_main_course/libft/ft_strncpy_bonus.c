/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:53:44 by cgrayson          #+#    #+#             */
/*   Updated: 2021/05/10 14:27:05 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_bonus(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
