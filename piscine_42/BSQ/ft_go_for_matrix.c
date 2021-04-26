/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_for_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:00 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:42:04 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_go_for_matrix(int **blocs, u_point *rul)
{
	int code;

	while ((rul.y + rul.length_side) < rul.lines_num)
	{
		code = ft_binari_search(rul.x, rul.y, blocs);
		if (code == 0)
		{
			rul.bigest_square[0] = rul.x;
			rul.bigest_square[1] = rul.y;
			rul.bigest_square[2] = rul.length_side;
			rul.length_side++;
		}
		else if ((rul.x + code + 1 + rul.length_side) >= rul.colum_num)
		{
			rul.y++;
			rul.x = 0;
		}
		else
			rul.x = code + 1;
	}
	ft_output(blocs, rul);
}
