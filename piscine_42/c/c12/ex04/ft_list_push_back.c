/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:00:25 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 16:00:58 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *res;

	if (*begin_list)
	{
		res = *begin_list;
		while (res->next)
			res = res->next;
		res->next = ft_create_elem(data);
	}
	*begin_list = ft_create_elem(data);
}
