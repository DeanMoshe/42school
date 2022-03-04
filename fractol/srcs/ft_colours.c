/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:50:28 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/28 18:26:47 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_rgbt(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_put_my_pix(t_img *img, int x, int y, int colour)
{
	char	*dest;

	if (x >= 0 && y >= 0)
	{
		dest = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)dest = colour;
	}
}

void	ft_colour_pix_mdbr(int n, int x, int y, t_img *img)
{
	int		colour;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	r = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.15) / 0.5));
	g = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.78) / 0.5));
	b = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.67) / 0.5));
	colour = ft_rgbt(0, r, g, b);
	if (n < img->max_iter && n > 0)
		ft_put_my_pix(img, x, y, colour);
	else
		ft_put_my_pix(img, x, y, 0x00);
}

void	ft_colour_pix_jul(int n, int x, int y, t_img *img)
{
	int		colour;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	r = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.85) / 0.5));
	g = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.98) / 0.5));
	b = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.21) / 0.5));
	colour = ft_rgbt(0, r, g, b);
	if (n < img->max_iter && n > 0)
		ft_put_my_pix(img, x, y, colour);
	else
		ft_put_my_pix(img, x, y, 0x00);
}
