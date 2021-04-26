/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:36:12 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/24 19:57:44 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_rev_params(char **argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	while (i > 0)
	{
		ft_putstr(argv[i - 1]);
		ft_putchar('\n');
		i--;
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	ft_rev_params(argv);
}
