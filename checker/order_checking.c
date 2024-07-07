/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:48:33 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 20:23:50 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 *	Checks is t_stack stack is sorted. Returns 1 in case of it is, 
 *	otherwise, returns 0. cahr direction definnes the order to check: 
 *	from minor to major is indicated by 'd' and reverse order by 'u'.
 */

int	ft_isorted(t_stack stack)
{
	int	aux_pointer;

	aux_pointer = stack.pointer;
	if (stack.size < 2)
		return (1);
	while (aux_pointer > 0)
	{
		if (stack.array[aux_pointer] > stack.array[aux_pointer - 1])
			return (0);
		aux_pointer--;
	}
	return (1);
}
