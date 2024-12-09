/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:15 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 17:19:18 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_boolean.h"
# include <limits.h>

typedef struct s_elem
{
	int				value;
	struct s_elem	*target;
	int				push_price;
	int				position;
	t_bool			above;
	t_bool			cheapest;
}	t_elem;

typedef struct s_stack
{
	t_elem	**elems;
	int		max_size;
	int		act_size;
}	t_stack;

void	push_swap(t_stack *a, t_stack *b, int argc);

t_bool	is_stack_valid(t_stack *stack);
void	ft_put_error(void);
void	free_stack(t_stack *stack);
void	free_argv(char *argv[]);
void	free_all_stacks(t_stack *a, t_stack *b);

void	update_stack_values(t_stack *stack);
void	init_stacks(t_stack *a, t_stack *b);

t_bool	has_min_amount_of_elems(t_stack *stack, int min_size);
t_bool	is_possible_swap_or_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap(int *a, int *b);
void	reverse_rotate(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

t_bool	is_value_in_stack(t_stack *a, int value);
void	add_new_element(t_stack *a_stack, int i, long temp);
t_bool	is_argv_i_valid(char *argv);
void	genarate_stacks(t_stack **a, t_stack **b, int argc, char **argv);

t_bool	ft_is_sorted(t_stack *a);
t_elem	*find_smallest_element(t_stack *stack);
void	rotate_until_element_on_top(t_stack *stack,
			t_elem *element, char stack_name);
void	move_from_b_to_a(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a);

#endif