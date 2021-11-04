/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:27:41 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/06 17:21:10 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_freedesc(t_pipex *desc)
{
	ft_freetab(desc->arg1);
	ft_freetab(desc->arg2);
	free(desc->path1);
	free(desc->path2);
	desc->path1 = NULL;
	desc->path2 = NULL;
}

char	**ft_getpath(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if ((ft_strncmp(env[i], "PATH=", 5) == 0))
			return (ft_split((env[i] + 5), ':'));
		i++;
	}
	return (NULL);
}

char	*ft_writepath(char **str, char *arg)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	while (str[i])
	{
		tmp = ft_strjoin(str[i], "/");
		res = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(res, F_OK | X_OK) == 0)
			return (res);
		free(res);
		i++;
	}
	return (NULL);
}
