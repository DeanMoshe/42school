/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:00:29 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/24 01:11:09 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = rules->philo_nb;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->write), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->ckeck_meal), NULL))
		return (1);
	return (0);
}

int	ft_init_philo(t_rules *rules)
{
	int	i;

	i = rules->philo_nb;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].x_ate = 0;
		rules->philo[i].left_fork_id = i;
		rules->philo[i].right_fork_id = (i + 1) % rules->philo_nb;
		rules->philo[i].last_meal = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	ft_init_all(t_rules *rules, char **argv)
{
	rules->philo_nb = ft_atoi(argv[1]);
	rules->death_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleep_time = ft_atoi(argv[4]);
	rules->all_ate = 0;
	rules->dead = 0;
	if (rules->philo_nb < 1 || rules->death_time < 0 || rules->eat_time < 0
		|| rules->sleep_time < 0 || rules->philo_nb > 250)
		return (1);
	if (argv[5])
	{
		rules->eat_nb = ft_atoi(argv[5]);
		if (rules->eat_nb <= 0)
			return (1);
	}
	else
		rules->eat_nb = -1;
	if (ft_init_mutex(rules))
		return (2);
	ft_init_philo(rules);
	return (0);
}
