/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:49:54 by cgrayson          #+#    #+#             */
/*   Updated: 2021/05/10 13:03:36 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_bonus(char *dest, const char *src)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (dest);
}
