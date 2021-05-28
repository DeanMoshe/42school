/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:34:04 by cgrayson          #+#    #+#             */
/*   Updated: 2021/05/10 13:34:52 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_prefix_bonus(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->item);
	if (root->left)
		ft_btree_apply_prefix_bonus(root->left, applyf);
	if (root->right)
		ft_btree_apply_prefix_bonus(root->right, applyf);
}
