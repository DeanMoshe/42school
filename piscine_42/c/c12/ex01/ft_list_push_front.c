/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:32:56 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 13:33:37 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *res;

	res = ft_create_elem(data);
	if (*begin_list)
	{
		res->next = *begin_list;
		*begin_list = res;
	}
}
