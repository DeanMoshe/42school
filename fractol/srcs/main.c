/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:49:51 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/26 17:28:45 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_window(t_info *desc, int height, int width)
{
	desc->mlx_ptr = mlx_init();
	desc->height = height;
	desc->width = width;
	desc->counter = 0;
	desc->win_ptr = mlx_new_window(desc->mlx_ptr, \
									desc->width, desc->height, "Fract-ol");
}

void	ft_init_img(t_img *img, t_info *desc)
{
	img->img = mlx_new_image(desc->mlx_ptr, desc->width, desc->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), \
								&(img->line_len), &(img->endian));
	img->max_iter = 70;
	img->zoom = 4;
	img->start_x = -2;
	img->start_y = -2;
	img->constant[0] = -0.7269;
	img->constant[1] = 0.1889;
}

void	ft_assign_func(t_info *desc)
{
	if (desc->type == 1)
	{
		desc->iter_f = &ft_iterate_mdbr;
		desc->col_f = &ft_colour_pix_mdbr;
	}
	else if (desc->type == 2)
	{
		desc->iter_f = &ft_iterate_jul;
		desc->col_f = &ft_colour_pix_jul;
	}
}

int	main(int argc, char **argv)
{
	t_info	desc;
	t_img	img;

	desc.type = ft_check_args(argc, argv);
	ft_init_window(&desc, HEIGHT, WIDTH);
	ft_init_img(&img, &desc);
	desc.img = &img;
	ft_assign_func(&desc);
	if (desc.type == 2 && argc == 4)
		ft_check_jul_params(argv, &img);
	if (desc.type == 2)
		img.max_iter = 300;
	mlx_key_hook(desc.win_ptr, &ft_key_hook, &desc);
	ft_draw_fractol(&desc, img.start_y, img.start_x, img.zoom);
	mlx_put_image_to_window(desc.mlx_ptr, desc.win_ptr, img.img, 0, 0);
	mlx_mouse_hook(desc.win_ptr, &ft_zoom, &desc);
	mlx_hook(desc.win_ptr, 6, (1L << 6), &ft_jul_const, &desc);
	mlx_hook(desc.win_ptr, 2, (1L << 0), &ft_colour_shift, &desc);
	mlx_loop(desc.mlx_ptr);
	return (EXIT_SUCCESS);
}
