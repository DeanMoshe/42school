/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:59:57 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/25 20:25:39 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_init_philo_bonus(t_rules *rules)
{
	int	i;

	i = rules->philo_nb;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].x_ate = 0;
		rules->philo[i].last_meal = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	ft_init_semaphore_bonus(t_rules *rules)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_checkmeal");
	rules->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, rules->philo_nb);
	rules->write = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	rules->check_meal = sem_open("/philo_checkmeal", O_CREAT, S_IRWXU, 1);
	if (rules->forks <= 0 || rules->write <= 0 || rules->check_meal <= 0)
		return (1);
	return (0);
}

int	ft_init_all_bonus(t_rules *rules, char **argv)
{
	rules->philo_nb = ft_atoi(argv[1]);
	rules->death_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleep_time = ft_atoi(argv[4]);
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
	if (rules->eat_nb == 1)
		rules->eat_nb++;
	if (ft_init_semaphore_bonus(rules))
		return (2);
	ft_init_philo_bonus(rules);
	return (0);
}
