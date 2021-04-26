/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:42:59 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/20 22:29:06 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	ft_str_is_printable(char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] != '\0')
	{
		res = ft_char_is_printable(str[i]);
		if (res == 0)
			return (0);
		i++;
	}
	return (1);
}
