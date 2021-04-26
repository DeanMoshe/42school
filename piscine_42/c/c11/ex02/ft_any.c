/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:14:31 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/02 16:14:55 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f) (char*))
{
	int i;

	i = 0;
	if (tab != (void*)0)
	{
		while (tab[i] != '\0')
		{
			if (f(tab[i]) != 0)
				return (1);
			i++;
		}
	}
	return (0);
}