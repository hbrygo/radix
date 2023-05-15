/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:07:54 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/15 18:53:36 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_suite(t_list **lst_a, t_list **lst_b)
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
			{
				ft_pa(lst_a, lst_b);
				ft_special(lst_a, lst_b);
			}
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

void	ft_first_part(t_list **lst_a, t_list **lst_b)
{
	int	middle;
	int	i[2];
	int	part;

	part = 1;
	i[0] = 0;
	middle = ft_middle(*lst_a);
	i[1] = ft_lstsize(*lst_a);
	while (i[0] < i[1])
	{
		(*lst_a)->partition = part;
		if ((*lst_a)->content < middle)
		{
			ft_pb(lst_a, lst_b);
			if (ft_lstsize(*lst_b) >= 2)
				ft_special(lst_a, lst_b);
		}
		else
		{
			ft_ra(lst_a);
			(*lst_a)->partition = 1;
		}
		i[0]++;
	}
	ft_suite(lst_a, lst_b);
}

int	ft_count(t_list *lst)
{
	int 	sort[2];
	int		i;
	t_list	*temp;

	i = 0;
	sort[0] = 0;
	sort[1] = 0;
	temp = lst;
	while (i < ft_lstsize(lst))
	{
		if (temp->partition == 0)
			sort[0]++;
		temp = temp->next;
		i++;
	}
	while (i > 0)
	{
		if (lst->partition != 0)
			sort[1]++;
		lst = lst->next;
		i--;
	}
	if (sort[0] > sort[1])
		return (1);
	return (0);
}

void	ft_next(t_list **lst_a, t_list **lst_b)
{
	int	middle;
	int	i[2];
	int	part;

	part = 1;
	i[0] = 0;
	middle = ft_middle2(*lst_a);
	i[1] = ft_lstsize2(*lst_a);
	while (i[0] < i[1])
	{
		(*lst_a)->partition = part;
		if ((*lst_a)->content < middle)
		{
			ft_pb(lst_a, lst_b);
			if (ft_lstsize(*lst_b) >= 2)
				ft_special(lst_a, lst_b);
		}
		else
		{
			ft_ra(lst_a);
			(*lst_a)->partition = 1;
		}
		i[0]++;
	}
	ft_suite(lst_a, lst_b);
}
// }

void	ft_tri(t_list **lst_a, t_list **lst_b, int next, int part)
{
	part = (*lst_a)->partition;
	while ((*lst_a)->partition <= part && (*lst_a)->partition >= part - 4)
	{
		if ((*lst_a)->content == next)
		{
			(*lst_a)->partition = 0;
			ft_ra(lst_a);
			while (ft_lstsize(*lst_b) > 0)
			{
				ft_pa(lst_a, lst_b);
				if ((*lst_a)->content == next && next++)
				{
					(*lst_a)->partition = 0;
					ft_ra(lst_a);
				}
				// ft_special(lst_a, lst_b);
			}
			next++;
		}
		else
			ft_pb(lst_a, lst_b);
	}
	// ft_next(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = NULL;
	lst_a = ft_set_lst(argc, argv);
	ft_first_part(&lst_a, &lst_b);
	ft_tri(&lst_a, &lst_b, 0, 2);
}

	// ft_printf("\n-----------------------------");
	// ft_printf("\nnext: %d", next);
	// ft_printf("part: %d", part);
	// ft_display(*lst_a);
	// ft_printf("-----------------------------\n");
	// sleep(2);