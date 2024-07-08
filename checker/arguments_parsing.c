/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinilla <tinilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:09:44 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/08 19:30:52 by tinilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 *	Returns an array of integers after parsing all arguments. 
 *	Size of array is stored in parameter int *num_of_int.
 *	If arguments contains invalid chararcters, an emty string, or a number 
 *	that exceed the range of an integer, it returns NULL.
 */

int	*ft_parse_args(char **argv)
{
	int	*num_list;

	if (ft_invalid_chars(argv) == -1)
		return (NULL);
	if (ft_empty_string(argv) == -1)
		return (NULL);
	if (ft_args_overflow(argv) == -1)
		return (NULL);
	num_list = ft_args_to_int(argv);
	if (ft_args_int_unique(num_list, ft_count_numbers(argv)) == -1)
		return (free(num_list), NULL);
	return (num_list);
}

/*
 *	Analyzes arguments and returns number of integers in
 *	all arguments
 */

int	ft_count_numbers(char **argv)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] && ft_isdigit(argv[i][j]) \
				&& ((argv[i][j + 1] == ' ' || !argv[i][j + 1])))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*
 *	Returns an array of integers of size int num_ints, extracted 
 *	from char **argv;
 */

int	*ft_args_to_int(char **argv)
{
	int		*num_list;
	char	**buff;
	int		i;
	int		j;

	num_list = (int *) malloc(ft_count_numbers(argv) * sizeof (int));
	i = 1;
	while (argv[i])
	{
		j = 0;
		buff = ft_split(argv[i], ' ');
		while (buff[j])
		{
			*num_list = ft_atoi(buff[j]);
			num_list++;
			j++;
		}
		i++;
		ft_free_split(buff);
	}
	return (num_list - ft_count_numbers(argv));
}

/*
 *	Procedure. Frees memory allocated in char **buff.
 */

void	ft_free_split(char **buff)
{
	char	**auxptr;

	auxptr = buff;
	while (*auxptr)
	{
		free(*auxptr);
		auxptr++;
	}
	free (buff);
}
