/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:31:43 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/04 20:55:13 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			*num_list;

	if (argc < 2)
		return (0);
	num_list = ft_parse_args(argv);
	if (!num_list)
		(ft_putstr_fd("Error\n", 2), exit(0));
	ft_createstack(&stack_a, ft_count_numbers(argv));
	ft_fill_stack(&stack_a, num_list, ft_count_numbers(argv));
	free(num_list);
	ft_createstack(&stack_b, ft_count_numbers(argv));
	push_swap(&stack_a, &stack_b);
	free(stack_a.array);
	free(stack_b.array);
}
