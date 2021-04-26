/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:03:39 by kkitsch           #+#    #+#             */
/*   Updated: 2021/02/21 16:03:57 by kkitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char pict_drow);

void	line_first(int a, int b)
{
	int i;

	i = 1;
	while ((i <= a) && (b > 0))
	{
		if (i == 1)
			ft_putchar('o');
		else if (i == a)
			ft_putchar('o');
		else
			ft_putchar('-');
		i++;
	}
}

void	line_general(int a, int b)
{
	int i;
	int j;

	j = 1;
	while ((j < b - 1) && (a > 0))
	{
		ft_putchar('\n');
		i = 1;
		while (i <= a)
		{
			if ((i == 1) || (i == a))
				ft_putchar('|');
			else
				ft_putchar(' ');
			i++;
		}
		j++;
	}
}

void	line_last(int a, int b)
{
	int i;

	i = 1;
	if (b > 1)
		ft_putchar('\n');
	while ((i <= a) && (b > 1))
	{
		if (i == 1)
			ft_putchar('o');
		else if (i == a)
			ft_putchar('o');
		else
			ft_putchar('-');
		i++;
	}
}

void	rush(int a, int b)
{
	line_first(a, b);
	line_general(a, b);
	line_last(a, b);
}
