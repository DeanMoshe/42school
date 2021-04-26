/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:30:04 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/20 21:34:14 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] != '\0')
	{
		res = ft_char_is_lowercase_alpha(str[i]);
		if (res == 0)
			return (0);
		i++;
	}
	return (1);
}
