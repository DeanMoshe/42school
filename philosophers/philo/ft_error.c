/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:24:36 by cgrayson          #+#    #+#             */
/*   Updated: 2022/01/21 14:45:57 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	ft_error(int error)
{
	if (error == 1)
		return (ft_write_error("Wrong argument"));
	if (error == 2)
		return (ft_write_error("Mutex initialising error"));
	return (1);
}
