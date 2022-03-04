/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:21:09 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/25 17:38:11 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return ((int)nbr * sign);
}

long long	ft_time_diff(long long past, long long pres)
{
	return (pres - past);
}

long long	ft_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_smart_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = ft_timestamp();
	while (!(rules->dead))
	{
		if (ft_time_diff(i, ft_timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	ft_action_print_bonus(t_rules *rules, int id, char *str)
{
	sem_wait(rules->write);
	if (!(rules->dead))
	{
		printf("%lli ", ft_timestamp() - rules->timestamp);
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	sem_post(rules->write);
	return ;
}
