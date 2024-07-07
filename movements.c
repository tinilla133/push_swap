/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:37:56 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/04 20:55:36 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char which_stack)
{
	t_element	element;

	if (stack->size > 1)
	{
		element = stack->array[stack->pointer];
		stack->array[stack->pointer] = stack->array[stack->pointer - 1];
		stack->array[stack->pointer - 1] = element;
	}
	if (which_stack)
		ft_printf("s%c\n", which_stack);
}

void	ft_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, '\0');
	ft_swap(stack_b, '\0');
	ft_printf("ss\n");
}

int	ft_push(t_stack *src, t_stack *dst, char dst_name)
{
	t_element	*element;

	element = ft_unstack(src);
	if (!element)
		return (-1);
	if (ft_stack(dst, *element) == -1)
		return (-1);
	ft_printf("p%c\n", dst_name);
	return (0);
}
