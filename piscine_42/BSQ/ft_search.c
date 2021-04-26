/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:40:18 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/11 13:40:22 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_search(int i, int *mas)
{
	int right;
	int left;
	int midle;

	left = 1;
	right = mas[0];
	while ((right - 1) != left)
	{
		midle = (left + right) / 2;
		if (i < mas[midle])
			right = midle;
		else if (i > mas[midle])
			left = midle;
		else
			return (-5);
	}
	return (mas[left]);
}
