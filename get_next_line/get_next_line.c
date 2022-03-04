/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:42:03 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/01 05:40:21 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freemem(char **str)
{
	free(*str);
	*str = NULL;
}

char	*ft_get_line(char *saved)
{
	char	*ptr;
	char	*res;

	if (!saved)
		return (NULL);
	ptr = ft_strchr(saved, '\n');
	if (!ptr && *saved)
		res = ft_strdup(saved);
	else if (ptr)
		res = ft_substr(saved, 0, (ptr - saved) + 1);
	else
		return (NULL);
	return (res);
}

char	*ft_update_static(char *saved, char *res)
{
	char	*tmp;

	if (!saved)
		return (0);
	tmp = ft_strdup(saved + ft_strlen(res));
	ft_freemem(&saved);
	saved = tmp;
	tmp = NULL;
	if (!saved)
	{
		ft_freemem(&saved);
		return (NULL);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	int			counter;
	char		buf[BUFFER_SIZE + 1];
	static char	*saved;
	char		*res;

	counter = 1;
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (counter != 0 && !(ft_strchr(saved, '\n')))
	{
		counter = read(fd, buf, BUFFER_SIZE);
		if (counter == -1)
		{
			ft_freemem(&saved);
			return (NULL);
		}
		buf[counter] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	res = ft_get_line(saved);
	saved = ft_update_static(saved, res);
	if (counter == 0)
		ft_freemem(&saved);
	return (res);
}
