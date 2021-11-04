/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:43:15 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/11 01:21:31 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex {
	int			fd_infile;
	int			fd_outfile;
	int			fd_pipe[2];
	char		*path1;
	char		*path2;
	char		**arg1;
	char		**arg2;
}				t_pipex;

void	ft_desc(t_pipex *desc, char **argv, char **env);
char	**ft_getpath(char **env);
char	**ft_split(char const *s, char c);
void	ft_freetab(char **str);
void	ft_freedesc(t_pipex *desc);
char	*ft_writepath(char **str, char *arg);
void	ft_dofork1(t_pipex *desc, char **argv, char **env);
void	ft_dofork2(t_pipex *desc, char **argv, char **env, pid_t *pid);
void	ft_pipex(t_pipex *desc, char **argv, char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(const char *s);

#endif