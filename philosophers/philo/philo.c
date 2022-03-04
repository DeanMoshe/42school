/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:25:16 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/25 12:44:24 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		res;

	if (argc != 5 && argc != 6)
		return (ft_write_error("Wrong amount of arguments"));
	res = ft_init_all(&rules, argv);
	if (res)
		return (ft_error(res));
	if (ft_launcher(&rules))
		return (ft_write_error("Threads error"));
	return (0);
}
