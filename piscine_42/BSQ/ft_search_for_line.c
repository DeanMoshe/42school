/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_for_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:45:31 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:45:36 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_search_for_line(int i1, int i2, int *mas)
{
	int a;
	int b;

	a = ft_search(i1, mas);
	b = ft_search(i2, mas);
	if (b == -5)
		return (i2);
	if (a == b)
		return (0);
	else
		return (b);
}
