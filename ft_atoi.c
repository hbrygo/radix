/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:27:21 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/19 12:04:47 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}
#include <stdio.h>
long int	ft_atoi(const char *str)
{
	long int	result;
	long int	last;
	long int	sign;

	result = 0;
	last = 0;
	sign = 1;
	str += skip((char *)str);
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		last = result;
	}
	return (result * sign);
}
