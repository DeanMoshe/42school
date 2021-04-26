/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:56:02 by mvirgini          #+#    #+#             */
/*   Updated: 2021/02/21 16:30:21 by mvirgini         ###   ########.fr       */
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
			ft_putchar(0x2F);
		}
		else if (i == a)
		{
			ft_putchar(0x5C);
		}
		else
		{
			ft_putchar(0x2A);
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
			ft_putchar(0x2A);
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
			ft_putchar(0x5C);
		}
		else if (i == a)
		{
			ft_putchar(0x2F);
		}
		else
		{
			ft_putchar(0x2A);
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
