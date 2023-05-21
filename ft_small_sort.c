/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:33:01 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/21 11:22:46 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_simulation(t_list *lst, int num)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (lst->content != num)
	{
		ft_ra_without(&lst);
		i++;
	}
	temp = i + 1;
	while (--temp > 0)
		ft_rra_without(&lst);
	while (lst->content != num)
	{
		ft_rra_without(&lst);
		j++;
	}
	temp = j + 1;
	while (--temp > 0)
		ft_ra_without(&lst);
	if (i < j)
		return (1);
	return (0);
}

int	ft_threesort(t_list **lst_a)
{
	if ((*lst_a)->content == 0)
	{
		ft_sa(*lst_a);
		ft_ra(lst_a);
		return (1);
	}
	if ((*lst_a)->content == ft_lstsize(*lst_a) - 1)
	{
		ft_ra(lst_a);
		if ((*lst_a)->content > (*lst_a)->next->content)
			ft_sa(*lst_a);
		return (1);
	}
	if ((*lst_a)->content != ft_lstsize(*lst_a) - 1 && (*lst_a)->content != 0)
	{
		if ((*lst_a)->content > (*lst_a)->next->content)
		{
			ft_sa(*lst_a);
			return (1);
		}
		ft_rra(lst_a);
		return (1);
	}
	return (1);
}

int	ft_foursort(t_list **lst_a, t_list **lst_b)
{
	int	i;

	i = ft_simulation(*lst_a, 3);
	while ((*lst_a)->content != 3)
	{
		if (i == 1)
			ft_ra(lst_a);
		else
			ft_rra(lst_a);
	}
	ft_pb(lst_a, lst_b);
	if (ft_lstsize(*lst_b) == 2 && (*lst_b)->content > (*lst_b)->next->content)
		ft_sb(*lst_b);
	if (ft_issort(*lst_a) == 0)
		ft_threesort(lst_a);
	ft_pa(lst_a, lst_b);
	ft_ra(lst_a);
	return (1);
}

int	ft_fivesort(t_list **lst_a, t_list **lst_b)
{
	int	i;

	i = ft_simulation(*lst_a, 4);
	while ((*lst_a)->content != 4)
	{
		if (i == 1)
			ft_ra(lst_a);
		else
			ft_rra(lst_a);
	}
	ft_pb(lst_a, lst_b);
	ft_foursort(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
	ft_ra(lst_a);
	return (1);
}
