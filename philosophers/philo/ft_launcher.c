/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:31:36 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/27 01:53:24 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eats(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	ft_action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	ft_action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->ckeck_meal));
	ft_action_print(rules, philo->id, "is eating");
	philo->last_meal = ft_timestamp();
	pthread_mutex_unlock(&(rules->ckeck_meal));
	ft_smart_sleep(rules->eat_time, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	ft_exit_launcher(t_rules *rules, t_philo *phi)
{
	int	i;

	i = -1;
	while (++i < rules->philo_nb)
		pthread_join(phi[i].thread_id, NULL);
	i = -1;
	while (++i < rules->philo_nb)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->write));
}

void	ft_death_check(t_rules *r, t_philo *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->philo_nb && !(r->dead))
		{
			pthread_mutex_lock(&(r->ckeck_meal));
			if (ft_time_diff(p[i].last_meal, ft_timestamp()) > r->death_time)
			{
				ft_action_print(r, i, "died");
				r->dead = 1;
				exit(1);
			}
			pthread_mutex_unlock(&(r->ckeck_meal));
			usleep(100);
		}
		if (r->dead)
			break ;
		i = 0;
		while (r->eat_nb != -1 && i < r->philo_nb && p[i].x_ate >= r->eat_nb)
			i++;
		if (i == r->philo_nb)
			r->all_ate = 1;
	}
}

void	*ft_thread(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->dead))
	{
		ft_philo_eats(philo);
		if (rules->all_ate)
			break ;
		ft_action_print(rules, philo->id, "is sleeping");
		ft_smart_sleep(rules->sleep_time, rules);
		ft_action_print(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

int	ft_launcher(t_rules *rules)
{
	int			i;
	t_philo		*phi;

	i = 0;
	phi = rules->philo;
	rules->timestamp = ft_timestamp();
	while (i < rules->philo_nb)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, ft_thread, &(phi[i])))
			return (1);
		phi[i].last_meal = ft_timestamp();
		i++;
	}
	ft_death_check(rules, rules->philo);
	ft_exit_launcher(rules, phi);
	return (0);
}
