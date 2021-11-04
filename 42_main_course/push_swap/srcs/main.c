/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:34:45 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/20 20:05:20 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_algorithm(t_info *desc)
{
	t_stack		*stack_cpy;
	t_param		params;

	params = ft_init_params(desc);
	stack_cpy = ft_stack_cpy(desc->stack_a, desc, &params);
	ft_bubble_sort(stack_cpy);
	ft_set_target_index_cpy(stack_cpy);
	ft_set_target_index(stack_cpy);
	ft_free_stack(stack_cpy);
	ft_set_keep(desc);
	ft_push_keep_false(desc);
	while (!ft_stack_is_empty(desc->stack_b))
	{
		params.elem = desc->stack_b->first;
		ft_eval_actions(desc, &params);
		ft_sort(desc, &params);
	}
	if (!(ft_is_on_top(desc->stack_a, ft_find_smallest(desc->stack_a))))
		ft_bring_to_top(desc->stack_a, ft_find_smallest(desc->stack_a), desc);
	if (ft_stack_is_empty(desc->stack_a))
		ft_error(desc, NULL, NULL);
	ft_free_all(desc, NULL, NULL);
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	*desc;
	int		args;

	desc = ft_desc_init();
	if (argc >= 2)
	{
		args = ft_read_args(argc, argv, desc);
		if (ft_stack_is_empty(desc->stack_a))
			ft_error(desc, NULL, NULL);
		if (ft_stack_is_sorted(desc->stack_a))
		{
			ft_free_all(desc, NULL, NULL);
			exit (EXIT_SUCCESS);
		}
		if (args <= 5)
			ft_small_cases(desc);
		else
			ft_sort_algorithm(desc);
	}
	ft_error(desc, NULL, NULL);
	exit (EXIT_FAILURE);
}
