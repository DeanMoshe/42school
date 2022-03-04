/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:53:26 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/24 14:11:06 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal;
	struct s_rules	*rules;
	pthread_t		thread_id;
}					t_philo;

typedef struct s_rules
{
	int				philo_nb;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nb;
	int				dead;
	int				all_ate;
	long long		timestamp;
	pthread_mutex_t	ckeck_meal;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	write;
	t_philo			philo[250];
}					t_rules;

/*
** ------ ft_launcher.c ------
*/

void		ft_philo_eats(t_philo *philo);
void		ft_exit_launcher(t_rules *rules, t_philo *phi);
void		ft_death_check(t_rules *r, t_philo *p);
void		*ft_thread(void *void_philo);
int			ft_launcher(t_rules *rules);

/*
** ------ ft_init.c ------
*/

int			ft_init_mutex(t_rules *rules);
int			ft_init_philo(t_rules *rules);
int			ft_init_all(t_rules *rules, char **argv);

/*
** ------ ft_utils.c ------
*/

int			ft_atoi(const char *str);
long long	ft_time_diff(long long past, long long pres);
long long	ft_timestamp(void);
void		ft_smart_sleep(long long time, t_rules *rules);
void		ft_action_print(t_rules *rules, int id, char *str);

/*
** ------ ft_error.c ------
*/

int			ft_write_error(char *str);
int			ft_error(int error);

#endif
