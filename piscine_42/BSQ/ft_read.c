/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:00:30 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/10 23:00:34 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_open_read(int **mas, char *file, u_point *file_rules)
{
	char	*buf;
	int		res;
	int		i;

	i = 0;
	if (!(buf = malloc(sizeof(char) * (ft_lenfile(file) + 1))))
		return (0);
	if ((res = open(file, O_RDONLY)) < 0)
		return (0);
	while (read(res, &buf[i], 1) > 0)
		i++;
	if (close(res) < 0)
		return (0);
	if (ft_file_read(mas, buf, file_rules) == 0)
		return (0);
	free(buf);
	return (1);
}

int			ft_second_str_len(char *buf)
{
	int res;
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	res = 0;
	j = 0;
	while (buf[j] != '\0')
	{
		if (buf[j] == '\n')
		{
			if (k > 1 && res != i)
				return (0);
			res = i;
			i = 0;
			k++;
		}
		i++;
		j++;
	}
	return (res - 1);
}

int			ft_read_nbr(char *buf)
{
	int res;
	int i;
	int k;

	i = 0;
	k = 0;
	res = 0;
	while (buf[k] != '\n')
	{
		if (buf[k] > 47 && buf[k] < 58)
		{
			while ((buf[k] > 47 && buf[k] < 58) && buf[k] != '\n')
			{
				if (i == 0)
					res = buf[k] - '0';
				if (i != 0)
					res = res * 10 + (buf[k] - '0');
				i++;
				k++;
			}
			return (res);
		}
		k++;
	}
	return (0);
}

void		ft_read_char(u_point *file_rules, char *buf)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (buf[i] != '\n')
	{
		if (!((buf[i] > 8 && buf[i] < 14) || buf[i] == 32 ||
			(buf[i] > 47 && buf[i] < 58)))
		{
			if (k < 3)
			{
				if (k == 0)
					file_rules->empty = buf[i];
				else if (k == 1)
					file_rules->obstacle = buf[i];
				else if (k == 2)
					file_rules->full = buf[i];
			}
			k++;
		}
		i++;
	}
}
