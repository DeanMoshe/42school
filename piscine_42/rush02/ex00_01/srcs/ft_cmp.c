/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:03:50 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/07 16:03:53 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_conditions (char *buf, int k, char *dict)
{
	char *dig[3];
	char *res[6];

	dig[0] = buf[1];
	dig[1] = buf[2];
	dig[2] = '\0';
	if (buf[1] == 1)
	{
		res[0] = ft_search(buf[0], dict);
		res[1] = ft_search(((char)100), dict);
		res[2] = ft_search(dig, dict);
		res[3] = ft_search(((char)ft_recursive_power(1000, k)), dict);
		res[4] = '\0';
	}
	else
	{
		res[0] = ft_search(buf[0], dict);
		res[1] = ft_search(((char)100), dict);
		res[2] = ft_search(dig, dict); 
		res[3] = ft_search(buf[2], dict);
		res[4] = ft_search(((char)ft_recursive_power(1000, k)), dict);
		res[5] = '\0';
	}
	return (res);
}

char ft_cmp (char *str, char *dict)
{
	int				len;
	int				i;
	int				k;
	char			**res;
	char			buf[4];

	i = 0;
	k = 1;
	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
		res[0] = ft_search("0");
	res = malloc(sizeof(char) * 1000);
	if (value == NULL)
		return (NULL);
	while (len > 0)
	{
		while (buf < 4)
		{
			if (str[len - k] > 48 && str[len - k] < 58)
				buf[k] = str[len - k];
			else
				buf[k] = "x";
			k++;
		}
		buf[4] = '\0';
		res[i] = ft_conditions(buf, i, dict);
		len -= 3;
		i++;
	}
}
