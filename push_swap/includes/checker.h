/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:58:54 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:30:16 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include "push_swap.h"

int		ft_read_action(char *action, t_info *info);
int		ft_strcmp(const char *s1, const char *s2);
int		get_next_line(int fd, char **line, t_info *info);
char	*gnl_strjoin(char *s1, char *s2, t_info *info);
void	check_line(char *line, t_info *info);
int		ft_hasnewline(char *str);
char	*ft_newline(char *s, t_info *info);
char	*ft_prep_s(char *s);
int		ft_len(const char *s);
int		ft_isalpha(int c);

#endif
