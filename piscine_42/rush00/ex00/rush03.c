/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:25:34 by mvirgini          #+#    #+#             */
/*   Updated: 2021/02/21 15:38:52 by mvirgini         ###   ########.fr       */
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
		{
			ft_putchar('A');
		}
		else if (i == a)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
}

void	line_general_inside(int a)
{
	int i;

	i = 1;
	while (i <= a)
	{
		if ((i == 1) || (i == a))
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
}

void	line_general(int a, int b)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while ((j < b - 1) && (a > 0))
	{
		ft_putchar('\n');
		i = 1;
		line_general_inside(a);
		j++;
	}
}

void	line_last(int a, int b)
{
	int i;

	i = 1;
	if (b > 1)
	{
		ft_putchar('\n');
	}
	while ((i <= a) && (b > 1))
	{
		if (i == 1)
		{
			ft_putchar('A');
		}
		else if (i == a)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
}

void	rush(int a, int b)
{
	line_first(a, b);
	line_general(a, b);
	line_last(a, b);
}
