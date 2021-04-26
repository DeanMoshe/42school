/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:17:00 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/05 20:17:19 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *el;
	int c;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	el = *root;
	c = cmpf(item, el->item);
	if (c < 0)
			el->left = btree_insert_data(&el->left, item, cmpf);
	else if (c >= 0)
			el->right = btree_insert_data(&el->right, item, cmpf);
}
