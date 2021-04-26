/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:55:11 by cgrayson          #+#    #+#             */
/*   Updated: 2021/03/03 14:19:23 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_do_op(char **argv, long long a, long long b)
{
	t_fn t_fun[5];

	ft_p_fn(t_fun);
	if (argv[2][0] == 43 && argv[2][1] == '\0')
		ft_putnbr(t_fun[0](a, b));
	if (argv[2][0] == 45 && argv[2][1] == '\0')
		ft_putnbr(t_fun[1](a, b));
	if (argv[2][0] == 42 && argv[2][1] == '\0')
		ft_putnbr(t_fun[2](a, b));
	if (argv[2][0] == 47 && argv[2][1] == '\0')
	{
		if (b == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(t_fun[3](a, b));
	}
	if (argv[2][0] == 37 && argv[2][1] == '\0')
	{
		if (b == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(t_fun[4](a, b));
	}
}

int		main(int argc, char **argv)
{
	long long a;
	long long b;

	if (argv[2][0] != 43 && argv[2][0] != 45 && argv[2][0] != 42
		&& argv[2][0] != 47 && argv[2][0] != 37)
		ft_putstr("0\n");
	else if (argv[2][1] != '\0')
		ft_putstr("0\n");
	else if (argc == 4)
	{
		if (ft_is_number(argv[1]) == 1)
			a = ft_atoi(argv[1]);
		if (ft_is_number(argv[3]) == 1)
			b = ft_atoi(argv[3]);
		if (ft_is_number(argv[1]) == 1 || ft_is_number(argv[3]) == 1)
			ft_do_op(argv, a, b);
		ft_putstr("\n");
	}
	return (0);
}
