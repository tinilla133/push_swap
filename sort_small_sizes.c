/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:02:41 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/07 16:57:15 by fvizcaya         ###   ########.fr       */
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
		ft_reverse_rotate(stack, 'a');
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
	if (ft_isorted(*stack_a))
		return ;
	ft_rotate_to_head(stack_a, ft_find_lowest(*stack_a), 'a');
	ft_push(stack_a, stack_b, 'b');
	if (!ft_isorted(*stack_a))
		ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, 'a');
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_isorted(*stack_a))
		return ;
	while (stack_a->size > 3)
	{
		ft_rotate_to_head(stack_a, ft_find_lowest(*stack_a), 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	if (!ft_isorted(*stack_a))
		ft_sort_three(stack_a);
	while (stack_b->size > 0)
		ft_push(stack_b, stack_a, 'a');
}

void	ft_sort_six(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_isorted(*stack_a))
		return ;
	while (stack_a->size > 3)
	{
		ft_rotate_to_head(stack_a, ft_find_lowest(*stack_a), 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	if (!ft_isorted(*stack_a))
		ft_sort_three(stack_a);
	while (stack_b->size > 0)
		ft_push(stack_b, stack_a, 'a');
}
