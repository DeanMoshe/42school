/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:42:35 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/21 19:52:48 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;

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

char *ft_copy(char *s1)
{
	int i;
	char res;

	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;
	char res;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			while (str[i] != '\0' || to_find[j] != '\0')
			{
				if (ft_strcmp(str[i], to_find) == 0)
				{
					res = ft_copy(str[i]);
				}
			}
		}
	}
	return (res);
}
