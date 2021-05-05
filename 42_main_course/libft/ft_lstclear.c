/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:16:20 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/28 14:16:20 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		tmp;
	
	if (!*lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst->next;
		ft_lstdelone(*lst, del);
		*lst = &tmp;
	}
	*lst = NULL;
}
