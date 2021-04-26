/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:45:04 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:45:07 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_out_help(int il, int ic, u_point *rul)
{
	if ((il >= rul.x)
	&& (il < rul.x + rul.lengh_side)
	&& (ic >= rul.y)
	&& (ic < rul.y + rul.lengh_side))
		return (1);
	return (0);
}

void	ft_output(int **mas, u_point *rul)
{
	int il;
	int ic;
	int im;

	ic = 0;
	while (ic < rul.lines_num)
	{
		il = 0;
		im = 2;
		while (il < rul.colum_num)
		{
			if (ft_out_help)
				ft_putchar(rul.full);
			else if (il == mas[ic][im])
			{
				ft_putchar(rul.obstacle);
				im++;
			}
			else
				ft_putchar(rul.empty);
			il++;
		}
		ft_putchar('\n');
		ic++;
	}
}
