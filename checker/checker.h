/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:41:59 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/07 17:26:43 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int					pointer;
	int					max_size;
	int					size;
	int					*array;
}						t_stack;

int			ft_createstack(t_stack *stack, int max_size);
void		ft_fill_stack(t_stack *stack, int *numbers, int size);
int			ft_stack(t_stack *stack, int element);
int			*ft_unstack(t_stack *stack);
void		ft_swap(t_stack *stack);
void		ft_swap_both(t_stack *stack_a, t_stack *stack_b);
int			ft_push(t_stack *src, t_stack *dst);
void		ft_rotate(t_stack *stack);
void		ft_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse_rotate(t_stack *stack);
void		ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
int			ft_isorted(t_stack stack);
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
int			checker(t_stack *stack_a, t_stack *stack_b);
int			ft_ps_do_movement(t_stack *stack_a, t_stack *stack_b, \
				char *movement);

#endif