/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:56 by cgrayson          #+#    #+#             */
/*   Updated: 2021/05/10 14:05:51 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew_bonus(void *item)
{
	t_btree	*res;

	res = (t_btree *)malloc(sizeof(t_btree));
	if (!res)
		return (NULL);
	res->left = 0;
	res->right = 0;
	res->item = item;
	return (res);
}
