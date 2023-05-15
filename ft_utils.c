/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:06:31 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/15 18:40:53 by hubrygo          ###   ########.fr       */
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

int	ft_lower(t_list *lst)
{
	int	previous;

	previous = ft_higher(lst, 0);
	while (lst->content != 0)
	{
		if (lst->content < previous)
			previous = lst->content;
		lst = lst->next;
	}
	return (previous);
}

int	ft_middle2(t_list *lst)
{
	int	middle;
	int	lower;
	int	high;

	lower = ft_lower(lst);
	high = ft_higher(lst, 0);
	middle = lower + ((high - lower) / 2);
	return (middle);
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

void	ft_special(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->content > (*lst_a)->next->content && (*lst_b)->content < (*lst_b)->next->content)
		ft_ss(*lst_a, *lst_b);
	else if ((*lst_a)->content > (*lst_a)->next->content)
		ft_sa(*lst_a);
	else if ((*lst_b)->content < (*lst_b)->next->content)
		ft_sb(*lst_b);
}
