/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:33:13 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/07 16:47:53 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h> 
# include "libft/libft.h"

typedef struct s_element
{
	int					key;
	int					index;
}						t_element;

typedef struct s_stack
{
	int					pointer;
	int					max_size;
	int					size;
	t_element			*array;
}						t_stack;

int			ft_createstack(t_stack *stack, int max_size);
void		ft_fill_stack(t_stack *stack, int *numbers, int size);
int			ft_stack(t_stack *stack, t_element element);
t_element	*ft_unstack(t_stack *stack);
void		ft_swap(t_stack *stack, char which_stack);
void		ft_swap_both(t_stack *stack_a, t_stack *stack_b);
int			ft_push(t_stack *src, t_stack *dst, char dst_name);
void		ft_rotate(t_stack *stack, char which_stack);
void		ft_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse_rotate(t_stack *stack, char which_stack);
void		ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
int			ft_isorted(t_stack stack);
int			ft_sort_small(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_two(t_stack *stack);
void		ft_sort_three(t_stack *stack);
void		ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_six(t_stack *stack_a, t_stack *stack_b);
void		ft_simple_sort(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_larger(t_stack *stack_a, t_stack *stack_b, \
				int pivot, int interval);
void		ft_set_indexes(t_stack *stack);
int			ft_find_highest_index(t_stack stack);
int			ft_find_highest(t_stack stack);
int			ft_find_lowest(t_stack stack);
int			ft_find_lowest_index(t_stack stack);
void		ft_push_back(t_stack *stack_a, t_stack *stack_b);
int			push_swap(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate_to_head(t_stack *stack, int key, \
				char which_stack);
void		ft_print_stack(t_stack stack);
int			*ft_parse_args(char **argv);
int			ft_invalid_chars(char **argv);
int			ft_empty_string(char **argv);
int			ft_count_numbers(char **argv);
int			ft_args_int_unique(int *numbers, int size);
int			ft_str_int_overflow(char *str);
int			ft_args_overflow(char **argv);
int			*ft_args_to_int(char **argv);
void		ft_free_split(char **buff);
int			ft_sqrt(int nbr);

#endif