/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_console.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:09:06 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/10 23:09:18 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int 		ft_main_console(char *file_name)
{
	file_name = (char*)malloc(sizeof(char) * 9);
	file_name = "file.txt";
	if (ft_console_file() == 0)
		return (1);
	return (0);
}
