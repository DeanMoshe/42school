/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:27:47 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/19 20:48:29 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int *head;
	int *tail;
	int buf;

	head = tab;
	tail = tab + size - 1;
	while (head < tail)
	{
		buf = *head;
		*head = *tail;
		*tail = buf;
		head++;
		tail--;
	}
}
