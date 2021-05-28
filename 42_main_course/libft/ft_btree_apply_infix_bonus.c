/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:35:42 by cgrayson          #+#    #+#             */
/*   Updated: 2021/05/10 13:36:38 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix_bonus(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_apply_infix_bonus(root->left, applyf);
	applyf(root->item);
	if (root->right)
		ft_btree_apply_infix_bonus(root->right, applyf);
}
