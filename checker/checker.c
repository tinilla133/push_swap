/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:47:31 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 20:17:11 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*movement;

	while (1)
	{
		movement = get_next_line(0);
		if (!movement)
			return (free(movement), 0);
		if (ft_ps_do_movement(stack_a, stack_b, movement) == -1)
			return (-1);
		free (movement);
	}
	return (0);
}

/*
 *	Executes char * movement with t_stack *stack_a or 
 *	t_stack *stack_b. If movement is invalid, returns 1, 
 *	otherwise, returns 0.
 */

int	ft_ps_do_movement(t_stack *stack_a, t_stack *stack_b, char *movement)
{
	if (!ft_strncmp(movement, "sa\n", ft_strlen(movement)))
		return (ft_swap(stack_a), 0);
	if (!ft_strncmp(movement, "sb\n", ft_strlen(movement)))
		return (ft_swap(stack_b), 0);
	if (!ft_strncmp(movement, "ss\n", ft_strlen(movement)))
		return (ft_swap_both(stack_a, stack_b), 0);
	if (!ft_strncmp(movement, "ra\n", ft_strlen(movement)))
		return (ft_rotate(stack_a), 0);
	if (!ft_strncmp(movement, "rb\n", ft_strlen(movement)))
		return (ft_rotate(stack_b), 0);
	if (!ft_strncmp(movement, "rr\n", ft_strlen(movement)))
		return (ft_rotate_both(stack_a, stack_b), 0);
	if (!ft_strncmp(movement, "rra\n", ft_strlen(movement)))
		return (ft_reverse_rotate(stack_a), 0);
	if (!ft_strncmp(movement, "rrb\n", ft_strlen(movement)))
		return (ft_reverse_rotate(stack_b), 0);
	if (!ft_strncmp(movement, "rrr\n", ft_strlen(movement)))
		return (ft_reverse_rotate_both(stack_a, stack_b), 0);
	if (!ft_strncmp(movement, "pa\n", ft_strlen(movement)))
		return (ft_push(stack_b, stack_a), 0);
	if (!ft_strncmp(movement, "pb\n", ft_strlen(movement)))
		return (ft_push(stack_a, stack_b), 0);
	return (-1);
}
