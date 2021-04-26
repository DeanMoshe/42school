/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:17:08 by bkael             #+#    #+#             */
/*   Updated: 2021/03/07 15:44:43 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_lenfile(char *file)
{
	int		i;
	char	buffer;
	int		handle;

	i = 0;
	if ((handle = open(file, O_RDONLY)) < 0)
		return (-1);
	while (read(handle, &buffer, 1) > 0)
		i++;
	if (close(handle) < 0)
		return (-1);
	return (i);
}

void	ft_open_read(char *name, char *file)
{
	char	*buffer;
	int		handle;
	int		i;

	file = file ? file : "numbers.dict";
	i = 0;
	if (!(buffer = malloc(sizeof(char) * (ft_lenfile(file) + 1))))
	{
		ft_putstr("Dict Error\n", 1);
		return ;
	}
	if ((handle = open(file, O_RDONLY)) < 0)
	{
		ft_putstr("Dict Error\n", 1);
		return ;
	}
	while (read(handle, &buffer[i], 1) > 0)
		i++;
	if (close(handle) < 0)
	{
		ft_putstr("Dict Error\n", 1);
		return ;
	}
	ft_putstr(ft_search(buffer, name), 1);
	free(buffer);
}

int		main(int argc, char **argv)
{
	if (argc > 3)
		ft_putstr("Error\n", 1);
	else if (argc == 2)
	{
		if (ft_check_number(argv[1]))
			ft_open_read(argv[1], NULL);
		else
			ft_putstr("Error\n", 1);
	}
	else if (argc == 3)
	{
		if (ft_check_number(argv[2]))
			ft_open_read(argv[2], argv[1]);
		else
			ft_putstr("Error\n", 1);
	}
	else
		ft_putstr("Error: no arguments\n", 1);
}
