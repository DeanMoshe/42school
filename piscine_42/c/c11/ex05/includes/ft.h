/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:56:51 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/03 19:57:25 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_H
# define __FT_H

typedef long long	(*t_fn)(long long, long long);

void				ft_putchar(char c);
long long			ft_atoi(char *str);
void				ft_putstr(char *str);
long long			ft_is_number(char *str);
long long			ft_add(long long a, long long b);
long long			ft_ded(long long a, long long b);
long long			ft_inc(long long a, long long b);
long long			ft_dev(long long a, long long b);
long long			ft_mod(long long a, long long b);
void				ft_putnbr(long long nb);
void				ft_do_op(char **argv, long long a, long long b);
void				ft_p_fn(t_fn *t_fun);

#endif
