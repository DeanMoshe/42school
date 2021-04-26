/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:26:48 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 17:27:29 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*buf;

	while (begin_list && (*cmp)(begin_list->data, data_ref) == 0)
	{
		buf = begin_list->next;
		begin_list = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
	}
	list_ptr = begin_list;
	while (list_ptr->next)
	{
		if ((*cmp)(list_ptr->next->data, data_ref) == 0)
		{
			buf = list_ptr->next;
			list_ptr->next = buf->next;
			free_fct(list_ptr->next->data);
			free(list_ptr);
		}
		list_ptr = list_ptr->next;
	}
}
