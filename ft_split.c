/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:20:59 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/08 19:07:20 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_lstsplit(char *str)
{
	t_list	*temp;
	t_list	*lst;

	if (!str)
		return (0);
	lst = NULL;
	while (str[0] != '\0')
	{
		while (str && (str[0] < '0' || str[0] > '9'))
			str++;
		if (str)
		{
			temp = ft_lstnew(ft_atoi(str));
			ft_lstadd_back(&lst, temp);
		}
		while (str && str[0] > '0' && str[0] < '9')
		{
			str++;
		}
	}
	return (lst);
}
