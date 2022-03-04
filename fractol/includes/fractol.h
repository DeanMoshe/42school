/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:52:11 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/28 18:14:35 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ARROW_UP				65362
# define ARROW_DOWN				65364
# define ARROW_LEFT				65361
# define ARROW_RIGHT			65363
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5
# define ESC_KEY				65307
# define SHIFT_KEY				65505
# define HEIGHT					1000
# define WIDTH					1000

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			max_iter;
	long double	zoom;
	double		constant[2];
	double		start_x;
	double		start_y;
}				t_img;

typedef struct s_point
{
	double		x;
	double		y;
	double		dx;
	double		dy;
}				t_point;

typedef struct s_param
{
	double		res;
	double		curr;
	int			p;
	int			num;
}				t_param;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	t_img		*img;
	int			type;
	int			(*iter_f)(double, double, t_img*);
	void		(*col_f)(int, int, int, t_img*);
	int			counter;
}				t_info;

void	ft_init_window(t_info *win, int height, int width);
void	ft_init_img(t_img *img, t_info *win);
void	ft_assign_func(t_info *win);
void	ft_error(void);
void	ft_init_param(t_param *param);
double	ft_param(char *str);
void	ft_check_jul_params(char **argv, t_img *img);
int		ft_check_args(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_rgbt(int t, int r, int g, int b);
void	ft_put_my_pix(t_img *img, int x, int y, int colour);
void	ft_colour_pix_mdbr(int n, int x, int y, t_img *img);
void	ft_colour_pix_jul(int n, int x, int y, t_img *img);
int		ft_key_hook(int key_code, t_info *desc);
int		ft_zoom(int btn, int x, int y, t_info *desc);
int		ft_jul_const(int x, int y, t_info *desc);
int		ft_colour_shift(int key_code, t_info *desc);
void	ft_draw_fractol(t_info *desc, double start_y, \
						double start_x, double zoom);
int		ft_iterate_mdbr(double a, double b, t_img *img);
int		ft_iterate_jul(double a, double b, t_img *img);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif