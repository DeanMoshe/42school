/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrayson <cgrayson@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:07:02 by cgrayson          #+#    #+#             */
/*   Updated: 2021/10/20 19:15:14 by cgrayson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_elem
{
	int				value;
	int				t_i;
	bool			keep;
	struct s_elem	*next;
	struct s_elem	*curr;
}				t_elem;

typedef struct s_stack
{
	t_elem			*first;
}				t_stack;

typedef struct s_info
{
	int				max;
	int				counter;
	int				max_size;
	t_stack			*stack_a;
	t_stack			*stack_b;
}				t_info;

typedef struct s_param
{
	int				counter_a;
	int				counter_b;
	int				min_move;
	int				total;
	int				action_b;
	int				min_a;
	int				min_b;
	t_elem			*elem;
	t_elem			*best;
}				t_param;

void	ft_sort_algorithm(t_info *desc);
void	ft_set_target_index(t_stack *stack);
void	ft_set_target_index_cpy(t_stack *cpy);
void	ft_bubble_swap(t_elem **origin, t_elem **tmplist, \
						t_elem **elem, int *tmp);
void	ft_bubble_sort(t_stack *stack);
t_stack	*ft_stack_cpy(t_stack *stack, t_info *desc, t_param *params);
int		ft_largest_keep_a(t_elem *start, t_stack *stack, bool define);
t_elem	*ft_get_max_keep(t_stack *stack);
void	ft_set_keep(t_info *desc);
void	ft_push_keep_false(t_info *desc);
int		ft_opt_actions(int count_a, int count_b);
int		ft_find_ins(t_stack *stack, int num, t_elem *tmp, t_elem *prev);
t_elem	*ft_eval_actions(t_info *desc, t_param *par);
int		ft_abs_value(int num);
int		ft_min(int x, int y);
int		ft_max(int x, int y);
void	ft_sort_mins(t_info *desc, t_param *params);
void	ft_sort(t_info *desc, t_param *params);
size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_free_stack(t_stack *stack);
void	ft_free_all(t_info *desc, int *min_a, int *min_b);
void	ft_error(t_info *desc, int *min_a, int *min_b);
void	ft_push_other_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_push_end_plus_origin(t_stack *stack, int num, \
								t_elem *origin, t_info *desc);
void	ft_push_end(t_info *desc, int num);
void	pa(t_stack *first, t_stack *second, t_info *desc);
void	pb(t_stack *first, t_stack *second, t_info *desc);
void	ft_reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a, t_info *desc);
void	rrb(t_stack *stack_b, t_info *desc);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_info *desc);
t_elem	*ft_last_elem(t_stack *stack);
void	ft_rotate_stack(t_stack *stack);
void	ra(t_stack *stack_a, t_info *desc);
void	rb(t_stack *stack_b, t_info *desc);
void	rr(t_stack *stack_a, t_stack *stack_b, t_info *desc);
void	ft_sort_two(t_info *desc);
void	ft_sort_three(t_info *desc);
void	ft_prepare_stack(t_stack *stack_a, t_stack *stack_b, t_info *desc);
void	ft_sort_four_five(t_info *desc);
void	ft_small_cases(t_info *desc);
int		ft_find_biggest(t_stack *stack);
int		ft_find_smallest(t_stack *stack);
int		ft_is_on_top(t_stack *stack, int num);
void	ft_bring_to_top(t_stack *stack, int num, t_info *desc);
int		ft_binary_search(t_stack *stack, int num);
void	ft_push_args(char *str, t_info *desc, int *args);
int		ft_read_args(int argc, char **argv, t_info *desc);
int		ft_stack_length(t_stack *stack);
int		ft_stack_is_empty(t_stack *stack);
int		ft_stack_is_sorted(t_stack *stack);
void	ft_check_duplicates(t_info *desc);
long	ft_push_atoi(char *str, t_info *desc);
t_info	*ft_desc_init(void);
t_param	ft_init_params(t_info *desc);
void	ft_init_variables(int *i, int *pos, bool *end);
void	ft_swap_ab(t_stack *stack);
void	sa(t_stack *stack_a, t_info *desc);
void	sb(t_stack *stack_b, t_info *desc);
void	ss(t_stack *stack_a, t_stack *stack_b, t_info *desc);
int		ft_isdigit(int c);

#endif