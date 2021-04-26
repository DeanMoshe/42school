/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:59:33 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/10 22:59:39 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_lenfile(char *file)
{
	char	buf;
	int		res;
	int		i;

	i = 0;
	if ((res = open(file, O_RDONLY)) < 0)
		return (0);
	while (read(res, &buf, 1) > 0)
		i++;
	if (close(res) < 0)
		return (0);
	return (i);
}
