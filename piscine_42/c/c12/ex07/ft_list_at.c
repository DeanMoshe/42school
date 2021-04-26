/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:43 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 16:33:59 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list)
		return (0);
	if (nbr > 0)
	{
		while (i < nbr)
		{
			begin_list = begin_list->next;
			i++;
		}
		return (begin_list);
	}
	return (0);
}
