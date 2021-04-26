/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:41:47 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:41:50 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 			FT_H
# define 			FT_H

# include			<unistd.h>
# include			<fcntl.h>
# include			<stdlib.h>

typedef struct		u_list
{
	char			empty;
	char			obstacle;
	char			full;
	int				sq[3];
	int				lines_num;
	int				colum_num;
	int				length_side;
	int				x;
	int				y;
}					u_point;

void				ft_putstr(char *str, int out);
int					ft_lenfile(char *file);
int					ft_open_read(int **mas, char *file, u_point *file_rules);
int					ft_second_str_len(char *buf);
int					ft_read_nbr(char *buf);
void				ft_read_char(u_point *file_rules ,char *buf);
int					ft_two_lines(u_point *file_rules, char *buf);
int					ft_obstacles_malloc(int **mas, u_point *file_rules);
int					ft_obstacles(int **mas, u_point *file_rules, char *buf);
int					ft_file_read (int **mas, char *buf, u_point *file_rules);
void				ft_output(int x, int y, int len, int **mas);
void				ft_go_for_matrix(int **blocs, u_point *rul);
int					ft_binari_search(int x, int y, int **blocs, u_point *st);
int 				ft_console_file();
int					ft_search_for_line(int i1, int i2, int *mas);
int					ft_search(int i, int *mas);
int					ft_chek(u_point st);
int 				ft_main_console(char *file_name);

#endif
