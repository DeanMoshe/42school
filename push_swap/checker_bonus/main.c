/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:59:19 by cgrayson          #+#    #+#             */
/*   Updated: 2022/02/08 14:19:10 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] || s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int	ft_read_action(char *action, t_info *info)
{
	if (!ft_strcmp(action, "rb"))
		rb(info->stack_b, 0, info);
	else if (!ft_strcmp(action, "rr"))
		rr(info->stack_a, info->stack_b, 0, info);
	else if (!ft_strcmp(action, "rra"))
		rra(info->stack_a, 0, info);
	else if (!ft_strcmp(action, "rrb"))
		rrb(info->stack_b, 0, info);
	else if (!ft_strcmp(action, "rrr"))
		rrr(info->stack_a, info->stack_b, 0, info);
	else if (!ft_strcmp(action, "sa"))
		sa(info->stack_a, 0, info);
	else if (!ft_strcmp(action, "sb"))
		sb(info->stack_b, 0, info);
	else if (!ft_strcmp(action, "ss"))
		ss(info->stack_a, info->stack_b, 0, info);
	else if (!ft_strcmp(action, "pa"))
		pa(info->stack_b, info->stack_a, 0, info);
	else if (!ft_strcmp(action, "pb"))
		pb(info->stack_a, info->stack_b, 0, info);
	else if (!ft_strcmp(action, "ra"))
		ra(info->stack_a, 0, info);
	else
		ft_error(info, NULL, NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	char	*buf;

	info = ft_desc_init();
	if (argc > 2)
	{
		ft_read_args(argc, argv, info);
		while (get_next_line(0, &buf, info))
		{
			ft_read_action(buf, info);
			free(buf);
		}
		if (ft_stack_is_sorted(info->stack_a) && \
			ft_stack_is_empty(info->stack_b))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		ft_free_all(info, NULL, NULL);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
