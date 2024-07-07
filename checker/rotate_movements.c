/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:04:30 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 20:25:17 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate(t_stack *stack)
{
	int			element;
	int			i;

	if (stack->size > 1)
	{
		i = stack->pointer;
		element = stack->array[i];
		while (i)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[i] = element;
	}
}

void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate(t_stack *stack)
{
	int			element;
	int			i;

	if (stack->size > 1)
	{
		i = 0;
		element = stack->array[i];
		while (i < stack->pointer)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[i] = element;
	}
}

void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
