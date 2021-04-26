/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binari_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:45:44 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:45:48 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_binari_search(int x, int y, int **blocs, u_point *rul)
{
	int code;
	int i;

	i = y + rul->length_side;
	while (y < i)
	{
		code = ft_search_for_line(x, x + rul->length_side - 1, blocs[y]);
		if (code == 0)
			y++;
		else
			return (code);
	}
	return (0);
}
