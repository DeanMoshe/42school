/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:25:02 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/25 17:42:16 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit_launcher_bonus(t_rules *rules)
{
	int	i;
	int	res;

	i = 0;
	while (i < rules->philo_nb)
	{
		waitpid(-1, &res, 0);
		if (res != 0)
		{
			i = -1;
			while (++i < rules->philo_nb)
				kill(rules->philo[i].proc_id, 15);
			break ;
		}
		i++;
	}
}

void	ft_philo_eats_bonus(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	sem_wait(rules->forks);
	ft_action_print_bonus(rules, philo->id, "has taken a fork");
	sem_wait(rules->forks);
	ft_action_print_bonus(rules, philo->id, "has taken a fork");
	sem_wait(rules->check_meal);
	ft_action_print_bonus(rules, philo->id, "is eating");
	philo->last_meal = ft_timestamp();
	sem_post(rules->check_meal);
	ft_smart_sleep(rules->eat_time, rules);
	(philo->x_ate)++;
	sem_post(rules->forks);
	sem_post(rules->forks);
}

void	*ft_death_checker_bonus(void *void_philo)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	while (true)
	{
		sem_wait(rules->check_meal);
		if (ft_time_diff(philo->last_meal, ft_timestamp()) > rules->death_time)
		{
			ft_action_print_bonus(rules, philo->id, "died");
			rules->dead = 1;
			sem_wait(rules->write);
			exit(1);
		}
		sem_post(rules->check_meal);
		if (rules->dead)
			break ;
		usleep(1000);
		if (philo->x_ate >= rules->eat_nb && rules->eat_nb != -1)
			break ;
	}
	return (0);
}

void	ft_process_bonus(void *void_philo)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	philo->last_meal = ft_timestamp();
	pthread_create(&(philo->death_check), NULL, \
					ft_death_checker_bonus, void_philo);
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->dead))
	{
		ft_philo_eats_bonus(philo);
		if (philo->x_ate >= rules->eat_nb && rules->eat_nb != -1)
			break ;
		ft_action_print_bonus(rules, philo->id, "is sleeping");
		ft_smart_sleep(rules->sleep_time, rules);
		ft_action_print_bonus(rules, philo->id, "is thinking");
	}
	pthread_join(philo->death_check, NULL);
	if (rules->dead)
		exit(1);
	exit(0);
}

int	ft_launcher_bonus(t_rules *rules)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = rules->philo;
	rules->timestamp = ft_timestamp();
	while (++i < rules->philo_nb)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			ft_process_bonus(&(phi[i]));
		usleep(100);
	}
	ft_exit_launcher_bonus(rules);
	return (0);
}
