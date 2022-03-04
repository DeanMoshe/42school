/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:51:13 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/26 19:05:09 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractol(t_info *desc, double start_y, \
						double start_x, double zoom)
{
	int			y_index;
	int			x_index;
	int			num;
	t_point		point;

	point.dx = zoom / desc->width;
	point.dy = zoom / desc->height;
	point.y = start_y;
	y_index = 0;
	while (y_index < desc->height)
	{
		x_index = 0;
		point.x = start_x;
		while (x_index < desc->width)
		{
			num = desc->iter_f(point.x, point.y, desc->img);
			desc->col_f(num, x_index, y_index, desc->img);
			point.x += point.dx;
			x_index++;
		}
		point.y += point.dy;
		y_index++;
	}
}

int	ft_iterate_mdbr(double a, double b, t_img *img)
{
	int		i;
	double	new_a;
	double	new_b;
	double	const_a;
	double	const_b;

	i = 0;
	const_a = a;
	const_b = b;
	while (i < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		a = new_a + const_a;
		b = new_b + const_b;
		i++;
	}
	return (i);
}

int	ft_iterate_jul(double a, double b, t_img *img)
{
	int		i;
	double	new_a;
	double	new_b;
	double	const_a;
	double	const_b;

	i = 0;
	const_a = (img->constant)[0];
	const_b = (img->constant)[1];
	while (i < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		a = new_a + const_a;
		b = new_b + const_b;
		i++;
	}
	return (i);
}
