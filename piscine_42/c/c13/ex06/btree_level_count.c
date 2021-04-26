/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:28:58 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/05 21:30:29 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int ft_cmp (int left, int right)
{
	if (left > right)
		return (left);
	else
		return (riht);
}

int	btree_level_count(t_btree *root)
{
	int k;

	k = 1;
	if (!root)
		return (0);
	k = k + cmp(btree_level_count(root->left), btree_level_count(root->right);
	return (k);
}
