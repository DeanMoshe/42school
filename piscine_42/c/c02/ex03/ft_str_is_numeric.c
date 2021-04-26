/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:13:02 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/20 21:24:13 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_str_is_numeric(char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] != '\0')
	{
		res = ft_char_is_number(str[i]);
		if (res == 0)
			return (0);
		i++;
	}
	return (1);
}
