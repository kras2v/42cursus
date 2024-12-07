/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:46:49 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:21:48 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*find_smallest_element(t_stack *stack)
{
	int		i;
	t_elem	*min;

	if (!stack || stack->act_size <= 0)
		return (NULL);
	min = stack->elems[0];
	i = 0;
	while (i < stack->act_size)
	{
		if ((stack->elems[i])->value < min->value)
			min = (stack->elems[i]);
		i++;
	}
	return (min);
}

void	rotate_until_element_on_top(t_stack *stack,
									t_elem *element, char stack_name)
{
	while (stack->elems[0] != element)
	{
		if (stack_name == 'a')
		{
			if (element->above)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (element->above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	rotate_both_until_target(t_stack *a, t_stack *b,
									t_elem *cheapest, int reverse)
{
	while (a->elems[0] != cheapest->target
		&& b->elems[0] != cheapest)
	{
		if (reverse)
			rrr(a, b);
		else
			rr(a, b);
	}
	update_stack_values(a);
	update_stack_values(b);
}

void	move_from_b_to_a(t_stack *a, t_stack *b)
{
	t_elem	*cheapest;
	int		i;

	if (!a || !b || !a->elems || !b->elems)
		return ;
	i = 0;
	while (i < b->act_size && b->elems[i] != NULL && !b->elems[i]->cheapest)
		i++;
	cheapest = b->elems[i];
	if (cheapest->above && cheapest->target->above)
		rotate_both_until_target(a, b, cheapest, false);
	else if (!cheapest->above && !cheapest->target->above)
		rotate_both_until_target(a, b, cheapest, true);
	rotate_until_element_on_top(b, cheapest, 'b');
	rotate_until_element_on_top(a, cheapest->target, 'a');
	pa(a, b);
}
