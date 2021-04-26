/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:26:11 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 19:27:22 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *list_ptr;
	t_list *list_other_ptr;
	t_list *buf;

	list_ptr = begin_list;
	list_other_ptr = begin_list->next;
	while (begin_list)
	{
		if ((*cmp)(list_ptr->data, list_other_ptr->data) > 0)
		{
			buf->data = list_ptr->data;
			list_ptr->data = list_other_ptr->data;
			list_other_ptr->data = buf->data;
		}
	}
}
