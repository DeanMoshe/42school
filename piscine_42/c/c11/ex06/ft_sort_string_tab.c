/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:52:51 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/03 19:38:57 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	else
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] != s2[i])
			{
				return (s1[i] - s2[i]);
			}
			i++;
		}
		return (0);
	}
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[j]) > 0)
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
