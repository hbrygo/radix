/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:07:54 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/21 11:20:39 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_bits(int size)
{
	int	bits;

	bits = 0;
	while (size)
	{
		size = size >> 1;
		bits++;
	}
	return (bits);
}

static void	ft_radix(t_list **list_a, t_list **list_b)
{
	t_list	*temp;
	int		bits;
	int		size;
	int		n;
	int		i[2];

	size = ft_lstsize(*list_a);
	bits = ft_bits(size - 1);
	i[0] = -1;
	while (++i[0] < bits)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			temp = *list_a;
			n = temp->content;
			if (((n >> i[0]) & 1) == 1)
				ft_ra(list_a);
			else
				ft_pb(list_a, list_b);
		}
		while (*list_b)
			ft_pa(list_a, list_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		check;

	check = 0;
	if (argc == 1)
		return (0);
	lst_b = NULL;
	lst_a = ft_set_lst(argc, argv);
	if (lst_a == NULL)
		return (0);
	if (ft_issort(lst_a) == 1)
		check = 1;
	else if (ft_special(&lst_a, &lst_b) == 1)
		check = 1;
	if (check == 1)
	{
		ft_lstclear(lst_a);
		return (0);
	}
	ft_radix(&lst_a, &lst_b);
	ft_lstclear(lst_a);
	return (0);
}
