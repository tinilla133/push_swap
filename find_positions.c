/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:05:05 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/07 16:42:09 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *  Returns the position of the higest key element (t_element) 
 *  in t_stack stack.  
 */

int	ft_find_highest(t_stack stack)
{
	int	nbr;
	int	i;
	int	position;

	nbr = INT_MIN;
	i = stack.pointer;
	position = 0;
	while (i >= 0)
	{
		if (stack.array[i].key > nbr)
		{
			nbr = stack.array[i].key;
			position = i;
		}
		i--;
	}
	return (position);
}

/*
 *	Returns position of element of t_stack stack with 
 *	highest index.
 */

int	ft_find_highest_index(t_stack stack)
{
	int	nbr;
	int	i;
	int	position;

	nbr = INT_MIN;
	i = stack.pointer;
	position = 0;
	while (i >= 0)
	{
		if (stack.array[i].index > nbr)
		{
			nbr = stack.array[i].index;
			position = i;
		}
		i--;
	}
	return (position);
}

/*
 *  Returns the position of the lowest key element (t_element) 
 *  in t_stack stack.  
 */

int	ft_find_lowest(t_stack stack)
{
	int	nbr;
	int	i;
	int	position;

	nbr = INT_MAX;
	i = stack.pointer;
	position = 0;
	while (i >= 0)
	{
		if (stack.array[i].key < nbr)
		{
			nbr = stack.array[i].key;
			position = i;
		}
		i--;
	}
	return (position);
}

/*
 *	Returns position of element of t_stack stack with 
 *	lowest index.
 */

int	ft_find_lowest_index(t_stack stack)
{
	int	nbr;
	int	i;
	int	position;

	nbr = INT_MAX;
	i = stack.pointer;
	position = 0;
	while (i >= 0)
	{
		if (stack.array[i].index < nbr)
		{
			nbr = stack.array[i].index;
			position = i;
		}
		i--;
	}
	return (position);
}
