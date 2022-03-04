/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:51:45 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/28 18:29:06 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int key_code, t_info *desc)
{
	t_img	*img;

	img = desc->img;
	if (key_code == ESC_KEY)
		exit(EXIT_SUCCESS);
	if (key_code == ARROW_LEFT)
		img->start_x -= (0.15 * img->zoom);
	if (key_code == ARROW_RIGHT)
		img->start_x += (0.15 * img->zoom);
	if (key_code == ARROW_UP)
		img->start_y -= (0.15 * img->zoom);
	if (key_code == ARROW_DOWN)
		img->start_y += (0.15 * img->zoom);
	ft_draw_fractol(desc, img->start_y, img->start_x, img->zoom);
	mlx_put_image_to_window(desc->mlx_ptr, desc->win_ptr, img->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	ft_zoom(int btn, int x, int y, t_info *desc)
{
	t_img	*img;
	double	new_x;
	double	new_y;

	img = desc->img;
	if (btn == MOUSE_SCROLL_DOWN)
	{
		new_x = (img->zoom * ((double)x / desc->width)) + img->start_x;
		new_y = (img->zoom * ((double)y / desc->height)) + img->start_y;
		img->start_x = new_x - (img->zoom / 2) * 0.35;
		img->start_y = new_y - (img->zoom / 2) * 0.35;
		img->zoom *= 0.75;
		img->max_iter = (int)(img->max_iter * 1.05);
	}
	if (btn == MOUSE_SCROLL_UP)
	{
		img->start_x -= (img->zoom / 2);
		img->start_y -= (img->zoom / 2);
		img->zoom /= 0.75;
		img->max_iter = (int)(img->max_iter / 1.05);
	}
	ft_draw_fractol(desc, img->start_y, img->start_x, img->zoom);
	mlx_put_image_to_window(desc->mlx_ptr, desc->win_ptr, img->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	ft_jul_const(int x, int y, t_info *desc)
{
	t_img	*img;
	double	new_x;
	double	new_y;

	if (desc->type == 2)
	{
		img = desc->img;
		new_x = (img->zoom * ((double)x / desc->width)) + img->start_x;
		new_y = (img->zoom * ((double)y / desc->height)) + img->start_y;
		(img->constant)[0] = new_x;
		(img->constant)[1] = new_y;
		ft_draw_fractol(desc, img->start_y, img->start_x, img->zoom);
		mlx_put_image_to_window(desc->mlx_ptr, desc->win_ptr, img->img, 0, 0);
	}
	return (0);
}

int	ft_colour_shift(int key_code, t_info *desc)
{
	void	(*col_f[2])(int, int, int, t_img*);
	t_img	*img;

	img = desc->img;
	col_f[0] = ft_colour_pix_mdbr;
	col_f[1] = ft_colour_pix_jul;
	if (key_code == SHIFT_KEY)
	{
		desc->col_f = col_f[desc->counter % 2];
		desc->counter++;
		ft_draw_fractol(desc, img->start_y, img->start_x, img->zoom);
		mlx_put_image_to_window(desc->mlx_ptr, desc->win_ptr, img->img, 0, 0);
	}
	return (0);
}
