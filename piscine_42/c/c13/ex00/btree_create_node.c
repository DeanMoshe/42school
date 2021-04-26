/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:35:22 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/05 19:35:37 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree	*res;

	if (!(res = (t_btree *)malloc(sizeof(t_btree))))
		return (0);
	res->left = 0;
	res->right = 0;
	res->item = item;
	return (res);
}
