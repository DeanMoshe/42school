/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:38:19 by cgrayson          #+#    #+#             */
/*   Updated: 2021/04/20 16:38:19 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define MAX_LONG	9223372036854775807

void			ft_putchar_fd(char c, int fd);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_numlen(long n);
int				ft_numlen_base(unsigned long n, int base);
int				ft_putnbr_base(unsigned long n, char *base);
char			*ft_itoa_base(char *str, unsigned long n, int base, int c);
char			*ft_uitoa(unsigned int n);

#endif
