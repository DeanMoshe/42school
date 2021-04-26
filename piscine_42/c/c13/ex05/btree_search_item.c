/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:46:37 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/05 20:46:59 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *item;

	if (!root)
		return (0);
	if (item = btree_search_item(root->left, data_ref, cmpf))
		return (item);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	if (item = btree_search_item(root->right, data_ref, cmpf))
		return (item);
}
