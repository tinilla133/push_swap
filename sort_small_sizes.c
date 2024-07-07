/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:02:41 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 19:34:05 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack *stack)
{
	if (stack->array[stack->pointer]. key > \
		stack->array[stack->pointer - 1].key)
		ft_swap(stack, 'a');
}

void	ft_sort_three(t_stack *stack)
{
	int	nbr[3];

	nbr[0] = stack->array[stack->pointer].index;
	nbr[1] = stack->array[stack->pointer - 1].index;
	nbr[2] = stack->array[stack->pointer - 2].index;
	if (ft_isorted(*stack))
		return ;
	if (nbr[0] < nbr[1] && nbr[0] < nbr[2] && nbr[1] > nbr[2])
	{
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (nbr[0] > nbr[1] && nbr[0] < nbr[2] && nbr[1] < nbr[2])
		ft_swap(stack, 'a');
	else if (nbr[0] < nbr[1] && nbr[0] > nbr[2] && nbr[1] > nbr[2])
		ft_reverse_rotate(stack, 'a');
	else if (nbr[0] > nbr[1] && nbr[0] > nbr[2] && nbr[1] < nbr[2])
		ft_rotate(stack, 'a');
	else if (nbr[0] > nbr[1] && nbr[0] > nbr[2] && nbr[1] > nbr[2])
	{
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	h_position;

	if (ft_isorted(*stack_a))
		return ;
	h_position = ft_find_highest_index(*stack_a);
	ft_rotate_to_head(stack_a, h_position, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, 'a');
	ft_rotate(stack_a, 'a');
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	h_position;

	h_position = ft_find_highest_index(*stack_a);
	ft_rotate_to_head(stack_a, h_position, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_sort_four(stack_a, stack_b);
	ft_push(stack_b, stack_a, 'a');
	ft_rotate(stack_a, 'a');
}

void	ft_sort_six(t_stack *stack_a, t_stack *stack_b)
{
	int	h_position;

	h_position = ft_find_highest_index(*stack_a);
	ft_rotate_to_head(stack_a, h_position, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_sort_five(stack_a, stack_b);
	ft_push(stack_b, stack_a, 'a');
	ft_rotate(stack_a, 'a');
}
