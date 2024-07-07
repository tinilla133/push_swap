/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:23:58 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/05 19:05:39 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Analyzes arguments and returns -1 if it finds any 
 *	invalid character. Otherwise, returns 0.
 */

int	ft_invalid_chars(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' \
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (-1);
			if (!ft_isdigit(argv[i][j]) && ((argv[i][j] == '+' \
				|| argv[i][j] == '-') && !ft_isdigit(argv[i][j + 1])))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
/*
 *	Analyzes arguments and it returns -1 if finds an empty string or 
 *	a string with only spaces.
 */

int	ft_empty_string(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (argv[i])
	{
		if (!ft_strlen(argv[i]))
			return (-1);
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				count++;
			j++;
		}
		if (!count)
			return (-1);
		i++;
	}
	return (0);
}

/*
 *  Returns -1 if there is a repeated number in int *numbers.
 *	Otherwise, returns 0.
 */

int	ft_args_int_unique(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
 * Returns an array of integers of length int numargs, that it receives 
 * as parameter, from list of args it receives also (char **args). 
 * If malloc fails, returns NULL.
 */

int	ft_args_overflow(char **argv)
{
	char	**buff;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		buff = ft_split(argv[i], ' ');
		while (buff[j])
		{
			if (ft_strlen(buff[j]) > 11 || ft_atol(buff[j]) > INT_MAX || \
				ft_atol(buff[j]) < INT_MIN)
				return (ft_free_split(buff), -1);
			j++;
		}
		ft_free_split(buff);
		i++;
	}
	return (0);
}
