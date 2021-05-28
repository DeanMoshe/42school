/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:32:00 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/28 14:32:00 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*res;
	t_list		*buf;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		buf = ft_lstnew(f(lst->content));
		if (!buf)
		{
			ft_lstdelone(buf, del);
			return (NULL);
		}
		ft_lstadd_back(&res, buf);
		lst = lst->next;
	}
	return (res);
}
