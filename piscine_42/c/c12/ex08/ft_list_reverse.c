/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:40:59 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/04 16:41:51 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list		*prev;
	t_list		*nxt;
	t_list		*cur;

	prev = 0;
	nxt = 0;
	cur = *begin_list;
	while (cur)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	*begin_list = prev;
}
