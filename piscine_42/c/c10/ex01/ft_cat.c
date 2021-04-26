/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:21:02 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/01 19:21:05 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str);

#define BUF_SIZE 64

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	int i;

	fd = 0;
	i = 0;
	while (argv != '\0')
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			ft_console_out(argv);
		else
			ft_file_out(argv);
}

void ft_console_out(char argv)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	return (0);
}


void ft_file_out(char argv)
{
	
}
