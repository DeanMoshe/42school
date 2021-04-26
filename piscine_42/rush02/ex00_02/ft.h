/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:19:44 by bkael             #+#    #+#             */
/*   Updated: 2021/03/07 15:48:11 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_check_number(char *str);
void	ft_putstr(char *str, int out);
char	*ft_search(char *argv, char *dict);
int		ft_isspace(char c);
void	ft_cmp(char *str, char *dict);
int		ft_strlen(char *str);
char	*ft_recursive_power(int power);
void	ft_putarr(char **str);

#endif
