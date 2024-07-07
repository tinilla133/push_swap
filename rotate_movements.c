/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:04:30 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/04 19:18:08 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack, char which_stack)
{
	t_element	element;
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
		if (which_stack)
			ft_printf("r%c\n", which_stack);
	}
}

void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, '\0');
	ft_rotate(stack_b, '\0');
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_stack *stack, char which_stack)
{
	t_element	element;
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
		if (which_stack)
			ft_printf("rr%c\n", which_stack);
	}
}

void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a, '\0');
	ft_reverse_rotate(stack_b, '\0');
	ft_printf("rrr\n");
}
