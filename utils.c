/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:25:02 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/04 20:58:25 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Returns the square root of the number passed as parameter.
 */

int	ft_sqrt(int nbr)
{
	int	i;

	i = 1;
	if (!nbr)
		return (0);
	while (i * i < nbr)
		i++;
	if (i * i == nbr)
		return (i);
	return (--i);
}
