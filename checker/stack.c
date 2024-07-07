/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:27:10 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/04 14:03:37 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 *  Creates an empty stack of maximum size max_size. 
 *  Returns -1 if call to malloc fails. Otherwise, 
 *  returns 0.
 */

int	ft_createstack(t_stack *stack, int max_size)
{
	stack->pointer = -1;
	stack->max_size = max_size;
	stack->size = 0;
	stack->array = (int *) malloc (max_size * sizeof (int));
	if (!stack->array)
		return (-1);
	return (0);
}

/*
 *  Pushes an element into stack. Returns -1 if stack is full or 
 *  call to malloc fails. Else, it returns 0.
 */

int	ft_stack(t_stack *stack, int element)
{
	if (stack->size == stack->max_size)
		return (-1);
	stack->pointer++;
	stack->size++;
	stack->array[stack->pointer] = element;
	return (0);
}
/*
 *  Pops an element from stack. Function returns pointer to 
 *  poped element. If stack is empty it returns NULL. 
 */

int	*ft_unstack(t_stack *stack)
{
	int	*ptr_element;

	if (stack->pointer == -1)
		return (NULL);
	ptr_element = &stack->array[stack->pointer];
	stack->pointer--;
	stack->size--;
	return (ptr_element);
}

/*
 *  Procedure. Fill the stack with arguments passed as array 
 *  of num_args strings. Stack is filled with strings converted 
 *  to integers.
 */

void	ft_fill_stack(t_stack *stack, int *numbers, int size)
{
	size -= 1;
	numbers += size;
	while (size >= 0)
	{
		ft_stack(stack, *numbers);
		numbers--;
		size--;
	}
}

void	ft_print_stack(t_stack stack)
{
	int	i;

	i = stack.pointer;
	if (i == -1)
		return ;
	ft_printf("STACK size: %d max_size: %d pointer: %d\n", \
				stack.size, stack.max_size, stack.pointer);
	ft_printf("[STACK]-->");
	while (i > -1)
	{
		if (i < stack.pointer)
			ft_printf("          ");
		ft_printf("[%d]\n", stack.array[i]);
		i--;
	}
	if (stack.pointer > 0)
		ft_printf("          ");
	ft_printf("\n");
}
