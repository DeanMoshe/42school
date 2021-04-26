/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgrodd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:59:32 by qgrodd            #+#    #+#             */
/*   Updated: 2021/03/06 18:06:26 by qgrodd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*letters_value(int str, char **dict)
{
	int		i;
	int 	j;
	char	*value;

	i = 0;
	j = 0;
	while(dict[str][i] != ':')
		i++;
	i++;
	while(dict[str][i] == ' ')
		i++;
	j = i;
	while(dict[str][j] != '\0')
		j++;
	value = malloc(sizeof(char) * j);
	if (value == NULL)
		return (NULL);
	j = 0;
	while(dict[str][i] != '\0')
	{
		if(dict[str][i] >= 32 && dict[str][i] <= 126)
			value[j] = dict[str][i];
		i++;
		j++;
	}
	value[j] = '\0';
	while(value[j-1] == ' ' && j != 0)
	{
		value[j-1] = '\0';
		j--;
	}
	if(value[0] == '\0')
		return(0);
	else
		value[j] = '\n';
	return (value);
}

int	 main(int argc, char **argv)
{
    (void)argc;
	char *out;
	out = letters_value(1, argv);
	while(*out)
	{
		printf("%c", *out);
		out++;
	}
}
