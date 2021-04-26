/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:47:57 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 17:48:15 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list1 || begin_list2)
	{
		while (begin_list1)
		{
			begin_list1 = begin_list1->next;
		}
		while (begin_list2)
		{
			begin_list1 = begin_list2;
			begin_list1->next = 0;
			begin_list1 = begin_list1->next;
			begin_list2 = begin_list2->next;
		}
	}
}
