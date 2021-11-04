/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:34:45 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/15 14:22:18 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_desc(t_pipex *desc, char **argv, char **env)
{
	char	**str;

	str = ft_getpath(env);
	if (str == NULL)
	{
		ft_putendl_fd("Unset PATH", 2);
		exit(EXIT_FAILURE);
	}
	desc->arg1 = ft_split(argv[2], ' ');
	desc->arg2 = ft_split(argv[3], ' ');
	desc->path1 = ft_writepath(str, desc->arg1[0]);
	desc->path2 = ft_writepath(str, desc->arg2[0]);
	ft_freetab(str);
	if (desc->path1 == NULL || desc->path2 == NULL)
	{
		ft_putendl_fd("Incorrect command name", 2);
		ft_freedesc(desc);
		exit(EXIT_FAILURE);
	}
}

void	ft_dofork1(t_pipex *desc, char **argv, char **env)
{
	desc->fd_infile = open(argv[1], O_RDONLY);
	if (desc->fd_infile < 0)
	{
		ft_putendl_fd("Can't read the argument: file1", 2);
		ft_freedesc(desc);
		exit(EXIT_FAILURE);
	}
	close(desc->fd_pipe[0]);
	dup2(desc->fd_pipe[1], STDOUT_FILENO);
	close(desc->fd_pipe[1]);
	dup2(desc->fd_infile, STDIN_FILENO);
	if (execve(desc->path1, desc->arg1, env) == -1)
	{
		ft_freedesc(desc);
		ft_putendl_fd("cmd1 not found", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_dofork2(t_pipex *desc, char **argv, char **env, pid_t *pid)
{
	waitpid(*pid, NULL, WNOHANG);
	desc->fd_outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (desc->fd_outfile < 0)
	{
		ft_putendl_fd("Can't read the argument: file2", 2);
		ft_freedesc(desc);
		exit(EXIT_FAILURE);
	}
	close(desc->fd_pipe[1]);
	dup2(desc->fd_pipe[0], STDIN_FILENO);
	close(desc->fd_pipe[0]);
	dup2(desc->fd_outfile, STDOUT_FILENO);
	if (execve(desc->path2, desc->arg2, env) == -1)
	{
		ft_freedesc(desc);
		ft_putendl_fd("cmd2 not found", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_pipex(t_pipex *desc, char **argv, char **env)
{
	pid_t	pid;

	if (pipe(desc->fd_pipe) == -1)
	{
		ft_putendl_fd("Fork failed", 2);
		exit(EXIT_FAILURE);
	}	
	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("Fork failed", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		ft_dofork1(desc, argv, env);
	else if (pid > 0)
		ft_dofork2(desc, argv, env, &pid);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	desc;

	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(EXIT_FAILURE);
	}
	ft_desc(&desc, argv, env);
	ft_pipex(&desc, argv, env);
	close(desc.fd_infile);
	close(desc.fd_outfile);
	ft_freedesc(&desc);
	exit(EXIT_SUCCESS);
}
