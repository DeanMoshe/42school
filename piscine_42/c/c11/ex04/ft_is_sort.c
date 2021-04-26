/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:46:58 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/02 16:47:34 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < length - 1)
	{
		if ((f(tab[i], tab[i + 1]) > 0) && (res >= 0))
			res = 1;
		else if ((f(tab[i], tab[i + 1]) > 0) && (res < 0))
			return (0);
		else if ((f(tab[i], tab[i + 1]) < 0) && (res <= 0))
			res = -1;
		else if ((f(tab[i], tab[i + 1]) < 0) && (res > 0))
			return (0);
		i++;
	}
	return (1);
}
