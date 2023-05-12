/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:12:32 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/12 12:46:42 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize2(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst && lst->content != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

void	ft_suite2(t_list **lst_a, t_list **lst_b)
{
	int	middle;
	int	i[3];

	middle = ft_middle(*lst_a);
	i[2] = 2;
	while (ft_lstsize(*lst_b) != 2)
	{
		middle = ft_middle(*lst_b);
		i[1] = ft_lstsize(*lst_b);
		i[0] = 0;
		while (i[0] <= i[1])
		{
			(*lst_b)->partition = i[2];
			if((*lst_b)->content > middle)
				ft_pa(lst_a, lst_b);
			else
				ft_rb(lst_b);
			i[0]++;
		}
		i[2]++;
	}
	if ((*lst_b)->content < (*lst_b)->next->content)
		ft_rb(lst_b);
	ft_pa(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
}

int	ft_tri2(t_list **lst_a, t_list **lst_b, int next)
{
	int	end;

	end = 1;
	while (end == 1  && (*lst_a)->partition != 0)
	{
		if ((*lst_a)->content == next)
		{
			ft_ra(lst_a);
			while (ft_lstsize(*lst_b) > 0)
			{
				ft_pa(lst_a, lst_b);
				if ((*lst_a)->content == next && next++)
					ft_ra(lst_a);
			}
			next++;
		}
		else
			ft_pb(lst_a, lst_b);
		if ((*lst_a)->content == 0)
			end = 0;
	}
	if ((*lst_a)->partition == 0)
		ft_end(lst_a, lst_b, next);
	return (next);
}

void	ft_last_part(t_list **lst_a, t_list **lst_b, int last)
{
	int	middle;
	int	i[2];
	int	part;

	part = 0;
	i[0] = 0;
	middle = ft_middle2(*lst_a);
	i[1] = ft_lstsize2(*lst_a);
	while (i[0] < i[1])
	{
		(*lst_a)->partition = part;
		if ((*lst_a)->content < middle)
			ft_pb(lst_a, lst_b);
		else
		{
			ft_ra(lst_a);
			(*lst_a)->partition = 1;
		}
		i[0]++;
	}
	while ((*lst_a)->content != last)
		ft_rra(lst_a);
	ft_ra(lst_a);
	ft_suite2(lst_a, lst_b);
	ft_tri2(lst_a, lst_b, last + 1);
	ft_display(*lst_b);
}
