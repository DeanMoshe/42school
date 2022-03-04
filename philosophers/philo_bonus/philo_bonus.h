/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:44:09 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/26 12:28:24 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdbool.h>

struct	s_rules;

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal;
	struct s_rules	*rules;
	pthread_t		death_check;
	pid_t			proc_id;
}					t_philo;

typedef struct s_rules
{
	int				philo_nb;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nb;
	int				dead;
	long long		timestamp;
	sem_t			*check_meal;
	sem_t			*forks;
	sem_t			*write;
	t_philo			philo[250];
}					t_rules;

/*
** ------ ft_init_bonus.c ------
*/

int			ft_init_philo_bonus(t_rules *rules);
int			ft_init_semaphore_bonus(t_rules *rules);
int			ft_init_all_bonus(t_rules *rules, char **argv);

/*
** ------ ft_launcher_bonus.c ------
*/

void		ft_exit_launcher_bonus(t_rules *rules);
void		ft_philo_eats_bonus(t_philo *philo);
void		*ft_death_checker_bonus(void *void_philo);
void		ft_process_bonus(void *void_philo);
int			ft_launcher_bonus(t_rules *rules);

/*
** ------ ft_utils_bonus.c ------
*/

int			ft_atoi(const char *str);
long long	ft_time_diff(long long past, long long pres);
long long	ft_timestamp(void);
void		ft_smart_sleep(long long time, t_rules *rules);
void		ft_action_print_bonus(t_rules *rules, int id, char *str);

/*
** ------ ft_error.c ------
*/

int			ft_write_error(char *str);
int			ft_error(int error);

#endif
