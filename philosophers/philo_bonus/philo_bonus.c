/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:54:08 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/25 20:26:06 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		res;

	if (argc != 5 && argc != 6)
		return (ft_write_error("Wrong amount of arguments"));
	res = ft_init_all_bonus(&rules, argv);
	if (res)
		return (ft_error(res));
	if (ft_launcher_bonus(&rules))
		return (ft_write_error("Error creating threads"));
	return (0);
}
