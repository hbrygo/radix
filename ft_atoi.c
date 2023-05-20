/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:27:21 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/20 11:35:04 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	skip(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

long int	ft_atoi(char *str)
{
	long int	result[3];

	result[0] = 0;
	result[1] = 0;
	result[2] = 1;
	if (ft_strlen(str) > 12)
		return (214748364955);
	str += skip((char *)str);
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			result[2] *= -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (214748364955);
	while (*str >= '0' && *str <= '9')
	{
		result[0] = result[0] * 10 + *str - '0';
		str++;
		result[1] = result[0];
	}
	if (*str)
		return (214748364955);
	return (result[0] * result[2]);
}
