/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:11:59 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/04 20:57:36 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_create_array(const t_stack stack)
{
	int	*array;
	int	aux_pointer;
	int	i;

	array = (int *) malloc(stack.size * sizeof (int));
	if (!array)
		return (NULL);
	aux_pointer = stack.pointer;
	i = 0;
	while (aux_pointer >= 0)
	{
		array[i] = stack.array[aux_pointer].key;
		i++;
		aux_pointer--;
	}
	return (array);
}

static void	ft_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	min;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		swap = array[i];
		array[i] = array[min];
		array[min] = swap;
		i++;
	}
}

void	ft_set_indexes(t_stack *stack)
{
	int	*aux_array;
	int	i;
	int	aux_pointer;
	int	found;

	aux_array = ft_create_array(*stack);
	i = 0;
	aux_pointer = stack->pointer;
	ft_sort_array(aux_array, stack->size);
	while (i < stack->size)
	{
		aux_pointer = stack->pointer;
		found = 0;
		while (aux_pointer >= 0 && !found)
		{
			if (aux_array[i] == stack->array[aux_pointer].key)
			{
				stack->array[aux_pointer].index = i;
				found = 1;
			}
			aux_pointer--;
		}
		i++;
	}
	free(aux_array);
}
