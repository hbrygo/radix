/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:06:31 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/21 11:23:19 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_error(void)
{
	write(2, "Error", 5);
	return (0);
}

int	ft_check(long int *tab, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (tab[i] < -2147483648 || tab[i] > 2147483647)
			return (0);
		while (j < i)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_display(t_list *lst)
{
	ft_printf("\n");
	while (lst)
	{
		ft_printf("\ncontent: %d,", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	ft_special(t_list **lst_a, t_list **lst_b)
{
	(void)lst_b;
	if (ft_lstsize(*lst_a) <= 1)
		return (1);
	if (ft_lstsize(*lst_a) == 2)
	{
		ft_sa(*lst_a);
		return (1);
	}
	if (ft_lstsize(*lst_a) == 3)
		return (ft_threesort(lst_a));
	if (ft_lstsize(*lst_a) == 4)
		return (ft_foursort(lst_a, lst_b));
	if (ft_lstsize(*lst_a) == 5)
		return (ft_fivesort(lst_a, lst_b));
	return (0);
}

int	ft_issort(t_list *lst)
{
	int	next;
	int	size;

	size = ft_lstsize(lst);
	next = 0;
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			next++;
		lst = lst->next;
	}
	if (next == size - 1)
		return (1);
	return (0);
}
