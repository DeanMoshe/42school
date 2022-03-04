/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:50:14 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/26 17:47:26 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	ft_init_param(t_param *param)
{
	param->curr = 1.0;
	param->p = 0;
	param->res = 0.0;
	param->num = 0;
}

double	ft_param(char *s)
{
	t_param	par;

	ft_init_param(&par);
	if (*s == '-')
	{
		s++;
		par.curr = -1;
	}
	while (*s)
	{
		if (*s == '.')
		{
			par.p++;
			s++;
			continue ;
		}
		if (par.p)
			par.curr /= 10.0;
		if (*s && ((par.p > 1 && *s == '.') || (!ft_isdigit(*s) && *s != '.')))
			ft_error();
		par.num = *s - '0';
		par.res = par.res * 10.0 + (double)par.num;
		s++;
	}
	return (par.res * par.curr);
}

void	ft_check_jul_params(char **argv, t_img *img)
{
	img->constant[0] = ft_param(argv[2]);
	img->constant[1] = ft_param(argv[3]);
}

int	ft_check_args(int argc, char **argv)
{
	char	*mdbr;
	char	*jul;

	mdbr = "Mandelbrot";
	jul = "Julia";
	if (argc > 1 && !ft_strncmp(argv[1], mdbr, ft_strlen(mdbr)))
		return (1);
	else if (argc > 1 && !ft_strncmp(argv[1], jul, ft_strlen(jul)))
		return (2);
	else
	{
		ft_putendl_fd("Please, choose fractal: Mandelbrot, Julia", 2);
		exit(EXIT_FAILURE);
	}
}
