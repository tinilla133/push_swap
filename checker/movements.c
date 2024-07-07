/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:37:56 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 20:25:01 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(t_stack *stack)
{
	int	element;

	if (stack->size > 1)
	{
		element = stack->array[stack->pointer];
		stack->array[stack->pointer] = stack->array[stack->pointer - 1];
		stack->array[stack->pointer - 1] = element;
	}
}

void	ft_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

int	ft_push(t_stack *src, t_stack *dst)
{
	int	*element;

	element = ft_unstack(src);
	if (!element)
		return (-1);
	if (ft_stack(dst, *element) == -1)
		return (-1);
	return (0);
}
