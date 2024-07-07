/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:56:08 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 19:31:51 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	interval;

	if (ft_isorted(*stack_a))
		return (0);
	if (stack_a->size <= 6)
		return (ft_sort_small(stack_a, stack_b), 0);
	pivot = 0;
	interval = ft_sqrt(stack_a->size) * 1.4;
	ft_sort_larger(stack_a, stack_b, pivot, interval);
	return (0);
}
/*
 *	Procedure. Sorts quantyties of numbers larger than six, 
 *	using an index as reference, which is the position the 
 *	numbers will should place when stack A is ordered.
 */

void	ft_sort_larger(t_stack *stack_a, t_stack *stack_b, \
			int pivot, int interval)
{
	while (!ft_isorted(*stack_a))
	{
		while (stack_a->size)
		{
			if (stack_a->array[stack_a->pointer].index <= pivot)
			{
				ft_push(stack_a, stack_b, 'b');
				ft_rotate(stack_b, 'b');
				pivot++;
			}
			else if (stack_a->array[stack_a->pointer].index <= pivot + interval)
			{
				ft_push(stack_a, stack_b, 'b');
				pivot++;
			}
			else
				ft_rotate(stack_a, 'a');
		}
		while (stack_b->size)
			ft_push_back(stack_a, stack_b);
	}
}

/*
 *	Procedure. Pushes back element with highest index from t_stack *stack_a
 *	to t_stack *stack_b.
 */

void	ft_push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	key_pos;

	key_pos = ft_find_highest_index(*stack_b);
	ft_rotate_to_head(stack_b, key_pos, 'b');
	ft_push(stack_b, stack_a, 'a');
}

/*
 *	Sorts stacks of small sizes. Returns 0 after sorting.
 *  Otherwise returns -1.
 */

int	ft_sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		return (ft_sort_two(stack_a), 0);
	if (stack_a->size == 3)
		return (ft_sort_three(stack_a), 0);
	if (stack_a->size == 4)
		return (ft_sort_four(stack_a, stack_b), 0);
	if (stack_a->size == 5)
		return (ft_sort_five(stack_a, stack_b), 0);
	if (stack_a->size == 6)
		return (ft_sort_six(stack_a, stack_b), 0);
	return (-1);
}
