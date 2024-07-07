/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:11 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/07 16:54:03 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_head(t_stack *stack, int position, \
								char which_stack)
{
	int	key;

	key = stack->array[position].key;
	while (stack->array[stack->pointer].key != key)
	{
		if (position >= stack->size / 2)
			ft_rotate(stack, which_stack);
		else
			ft_reverse_rotate(stack, which_stack);
	}
}
