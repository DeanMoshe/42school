/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:39:44 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:39:49 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

{
	char	buf[512];
	int		ret;
	int		fd;

	fd = open("file.txt", O_WRONLY | O_TRUNC);
	if (fd == -1)
		return (0);
	while ((ret = read(1, buf, 512)) > 0)
		write(fd, buf, ret);
	close(fd);
	return (1);
}
