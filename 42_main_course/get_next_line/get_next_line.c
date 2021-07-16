/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:42:03 by cgrayson          #+#    #+#             */
/*   Updated: 2021/07/16 15:07:44 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_and_return(char **str)
{
	free(*str);
	return (NULL);
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

int	ft_update_static(char **saved, char *res)
{
	char	*tmp;

	if (!saved)
		return (0);
	tmp = ft_strdup(*saved + ft_strlen(res));
	free(*saved);
	*saved = tmp;
	if (!*saved)
		ft_free_and_return(saved);
	return (1);
}

char	*get_next_line(int fd)
{
	int			counter;
	char		*buf;
	static char	*saved;
	char		*res;

	counter = 1;
	res = "\0";
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (counter != 0 && !(ft_strchr(saved, '\n')))
	{
		counter = read(fd, buf, BUFFER_SIZE);
		if (counter == -1)
			return (ft_free_and_return(&buf));
		buf[counter] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	free(buf);
	res = ft_get_line(saved);
	ft_update_static(&saved, res);
	return (res);
}
