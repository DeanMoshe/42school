/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:36:56 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/20 21:41:42 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_uppercase_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] != '\0')
	{
		res = ft_char_is_uppercase_alpha(str[i]);
		if (res == 0)
			return (0);
		i++;
	}
	return (1);
}
