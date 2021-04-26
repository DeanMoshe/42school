/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:05:11 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 16:05:41 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list		*res;
	t_list		*begin_list;
	int			i;

	i = 0;
	if (size > 0 && strs)
	{
		res = ft_create_elem(strs[0]);
		i++;
		while (i > 1 && i < size)
		{
			res = ft_create_elem(strs[i]);
			res->next = begin_list;
			begin_list = res;
		}
		return (begin_list);
	}
	return (0);
}
