/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:44:46 by cgrayson          #+#    #+#             */
/*   Updated: 2021/02/24 20:44:54 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

void    ft_print_params(char **argv)
{
    int i;

    i = 1;
    while (argv[i] != '\0')
    {
        ft_putstr(argv[i]);
        ft_putchar('\n');
        i++;
    }
}

void    ft_sort_params(char **argv)
{
    int i;
    int j;
    int len;
    char **buf;

    i = 1;
    len = 1;
    while (argv[len] != '\0')
        len++;
    while ( i < len)
    {
        j = 1;
        while (j < len - 1)
        {
            if (argv[i][j] > argv[i][j + 1])
            {
                buf = argv[i][j];
                argv[i][j] = argv[i][j + 1];
                argv[i][j + 1] = buf;
            }
            j++;
        }
        i++;
    }
    ft_print_params(argv);
}

int        main(int argc, char **argv)
{
    (void)argc;
    ft_sort_params(argv);
}
