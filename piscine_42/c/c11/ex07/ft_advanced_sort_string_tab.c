/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:41:09 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/03 19:41:14 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	while (tab[i] != '\0')
	{
		j = i + 1;
		while (tab[j] != '\0')
		{
			if (cmp(tab[i], tab[j]) > 0)
			{
				buf = tab[i];
				tab[i] = tab[j];
				tab[j] = buf;
			}
			j++;
		}
		i++;
	}
}
