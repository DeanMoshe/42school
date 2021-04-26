/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:27:17 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/23 19:28:22 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *int)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strlen_and_exclusion(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (0) ;
		while (str[j])
		{
			if (str[j] == str[i])
			{
				return (0) ;
			}
			j++;
		}
		i++;

	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;
	int res[43];
	long int num;
	int k;

	len = 0;
	k = 0;
	num = nbr;
	len = ft_strlen_and_exclusion(base);
	if (len > 1)
	{
		if (num < 0)
		{
			ft_putchar('-');
			num = -num;
		}
		while (num > len)
		{
			res[k] = num % len;
			num = num / len;
			k++;
		}
		res[k] = num;
		ft_putstr(res);
		while (k >= 0)
		{
			ft_putchar(base[res[k]]);
			k--;
		}
	}
}

int main()
{
  char c[] = {"01"};
  int a = 32;
  
  ft_putnbr_base(a, c);
}
