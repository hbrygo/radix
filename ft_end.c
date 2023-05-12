/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:40:23 by hugo              #+#    #+#             */
/*   Updated: 2023/05/12 12:47:08 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_suite3(t_list **lst_a, t_list **lst_b)
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

int	ft_tri3(t_list **lst_a, t_list **lst_b, int next)
{
	int	end;

	end = 1;
	while (end == 1)
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
	return (next);
}

void	ft_end(t_list **lst_a, t_list **lst_b, int last)
{
	int	middle;
	int	i[2];

	i[0] = 0;
	middle = ft_middle2(*lst_a);
	i[1] = ft_lstsize2(*lst_a);
	while (i[0] < i[1])
	{
		if ((*lst_a)->content < middle)
			ft_pb(lst_a, lst_b);
		else
			ft_ra(lst_a);
		i[0]++;
	}
	while ((*lst_a)->content != last - 1)
		ft_rra(lst_a);
	ft_ra(lst_a);
	ft_suite3(lst_a, lst_b);
	ft_tri3(lst_a, lst_b, last);
}