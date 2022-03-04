/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:01 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 11:37:30 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
	{
		len++;
		return (len);
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
