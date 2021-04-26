/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:52 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/08 15:20:55 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_two_lines(u_point *file_rules, char *buf)
{
	if ((file_rules->lines_num = ft_read_nbr(buf)) == 0)
		return (0);
	ft_read_char(file_rules, buf);
	if ((file_rules->colum_num = ft_second_str_len(buf)) == 0)
		return (0);
	if ((file_rules->obstacle == file_rules->full) ||
		(file_rules->obstacle == file_rules->empty)
		| (file_rules->empty == file_rules->full) ||
		NULL == file_rules || !file_rules->empty ||
		!file_rules->obstacle || !file_rules->full)
		return (0);
	return (1);
}

int			ft_obstacles_malloc(int **mas, u_point *file_rules, char *buf)
{
	int i;

	i = 0;
	if (!(mas = (int**)malloc(sizeof(int*) * (file_rules->lines_num) + 1)))
		return (0);
	while (i < file_rules->lines_num)
	{
		if (!(mas[i] = (int*)malloc(sizeof(int) * file_rules->colum_num) + 3))
			return (0);
		i++;
	}
	while (buf)
	{
		ft_obstacles(mas, file_rules, buf);
		buf++;
	}
	return (1);
}

int			ft_obstacles(int **mas, u_point *file_rules, char *buf)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	k = 2;
	j = 0;
	l = 0;
	while (j == 0 && buf[l] != '\n')
		l++;
	j++;
	i = 0;
	while (buf[l] != '\n')
	{
		if (buf[l] == file_rules->obstacle)
		{
			mas[j - 1][k] = i;
			k++;
		}
		l++;
		i++;
	}
	mas[j - 1][0] = k - 2;
	mas[j - 1][1] = -1;
	i = 0;
	k = 2;
	return (1);
}

int			ft_file_read(int **mas, char *buf, u_point *file_rules)
{
	if (!(file_rules = (u_point*)malloc(sizeof(u_point) + 1)))
		return (0);
	if (ft_two_lines(file_rules, buf) == 0)
		return (0);
	if (ft_obstacles_malloc(mas, file_rules, buf) == 0)
		return (0);
	return (1);
}

/*int			main(int argc, char **argv)
{
	int			**mas;
	char		*file_name;
	u_point		*file_rules;
	int			i;

	i = 1;
	if (argc == 1)
		i = ft_main_console(file_name);
	while (argc - i > 0)
	{
		if (argc != 1)
			file_name = argv[i];
		if (ft_open_read(mas, argv[i], file_rules) == 0)
			ft_putstr("error\n", 2);
		else
		{
			ft_go_for_matrix(mas, file_rules);
		}
		free(file_rules);
		ft_mas_free(mas);
		free(mas);
		i++;
	}
	return (0);
}*/
