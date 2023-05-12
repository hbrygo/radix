/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:06:31 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/11 21:11:45 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_higher(t_list *lst, int previous)
{
	while (lst)
	{
		if (previous < lst->content)
			previous = lst->content;
		lst = lst->next;
	}
	return (previous);
}

int	ft_middle(t_list *lst)
{
	t_list	*temp;
	int		middle;
	int		previous;
	int		i;

	i = ft_lstsize(lst) / 2;
	previous = 0;
	middle = 0;
	temp = lst;
	middle = ft_higher(lst, previous);
	while (i > 0)
	{
		previous = 0;
		lst = temp;
		while (lst)
		{
			if (lst->content > previous && lst->content < middle)
				previous = lst->content;
			lst = lst->next;
		}
		i--;
		middle = previous;
	}
	return (middle);
}
