/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:37:04 by cgrayson          #+#    #+#             */
/*   Updated: 2021/05/10 13:37:48 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix_bonus(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_apply_suffix_bonus(root->left, applyf);
	if (root->right)
		ft_btree_apply_suffix_bonus(root->right, applyf);
	applyf(root->item);
}
