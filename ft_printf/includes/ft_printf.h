/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:08:52 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/19 12:19:44 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** args - arg to print out
** width - width
** prc - precision
** zero - zero padding
** pnt - "."
** minus - "-"
** len - total_length (return value)
** sign - positive or negative number
** is_zero - is zero number
** perc - "%"
** space - space flag ' '
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_print
{
	va_list		args;
	int			width;
	int			prc;
	int			zero;
	int			pnt;
	int			minus;
	int			len;
	int			sign;
	int			is_zero;
	int			perc;
	int			space;
}				t_print;

t_print	*ft_set_tab(t_print *tab);
t_print	*ft_reset_tab(t_print *tab);
void	ft_update_tab (t_print *tab, int len);
int		ft_printf(const char *format, ...);
int		ft_get_type(t_print *tab, const char *format, int pos);
int		ft_get_flag(t_print *tab, const char *format, int pos);
int		ft_width_flag(t_print *tab, const char *format, int pos);
int		ft_space_flag(t_print *tab, int pos);
int		ft_zero_flag(t_print *tab, const char *format, int pos);
int		ft_precision_flag(t_print *tab, const char *format, int pos);
int		ft_minus_flag(t_print *tab, const char *format, int pos);
int		ft_asterisk_flag(t_print *tab, const char *format, int pos);
void	ft_check_precision(t_print *tab);
void	ft_check_width(t_print *tab);
int		ft_check_sign(t_print *tab, int i);
int		ft_check_flag(char c);
void	ft_output_char(t_print *tab);
void	ft_output_percent(t_print *tab);
void	ft_output_string(t_print *tab);
void	ft_write_pnt(t_print *tab);
int		ft_update_tab_string(t_print *tab, char *s, int len);
void	ft_output_int(t_print *tab);
void	ft_output_unsigned_int(t_print *tab);
void	ft_write_zero_point(t_print *tab);
void	ft_write_zero(t_print *tab);
void	ft_output_pointer(t_print *tab);
void	ft_write_null_ptr(t_print *tab);
void	ft_output_hexa_int(t_print *tab, int c);
void	ft_right_idupx(t_print *tab);
void	ft_left_idupx(t_print *tab);
void	ft_right_align(t_print *tab, int len);
void	ft_left_align(t_print *tab, int len);
void	ft_right_zero(t_print *tab);

#endif