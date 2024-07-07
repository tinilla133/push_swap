/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:35:19 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/06/03 19:59:22 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	integer;
	double	fraction;
	int		len;

	integer = (double) ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	fraction = (double) ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		fraction /= 10;
	if (integer >= 0)
		return (integer + fraction);
	else
		return (integer - fraction);
}
