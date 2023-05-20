/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:06:27 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/20 10:06:05 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_in_lst(long int *tab, int size)
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	i = -1;
	lst = NULL;
	while (++i < size)
	{
		temp = ft_lstnew(tab[i]);
		ft_lstadd_back(&lst, temp);
	}
	free(tab);
	return (lst);
}

long int	*ft_tri_tab(long int *tab, int size)
{
	int			i;
	long int	*new_tab;
	int			j;
	int			higher;

	j = 0;
	new_tab = malloc(sizeof(long int) * size);
	if (!new_tab)
		return (0);
	while (j < size)
	{
		i = 0;
		higher = 0;
		while (i < size)
		{
			if (tab[i] < tab[j])
				higher++;
			i++;
		}
		new_tab[j] = higher;
		j++;
	}
	free(tab);
	return (new_tab);
}

long int	*ft_lst_to_tab(long int *tab, t_list *lst, int *i)
{
	t_list		*temp;

	temp = lst;
	while (++i[0] < i[1])
	{
		tab[i[0]] = temp->content;
		temp = temp->next;
	}
	ft_lstclear(temp);
	return (tab);
}

void	*ft_num(t_list *lst)
{
	int			i[2];
	t_list		*return_lst;
	long int	*tab;

	i[0] = -1;
	i[1] = ft_lstsize(lst);
	tab = malloc(sizeof(long int) * i[1]);
	if (!tab)
	{
		ft_lstclear(lst);
		return (0);
	}
	tab = ft_lst_to_tab(tab, lst, i);
	if (ft_check(tab, i[1]) == 0)
	{
		free(tab);
		ft_lstclear(lst);
		return (ft_error());
	}
	tab = ft_tri_tab(tab, i[1]);
	return_lst = ft_in_lst(tab, i[1]);
	ft_lstclear(lst);
	return (return_lst);
}

void	*ft_set_lst(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	i = 0;
	while (++i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&lst, temp);
	}
	lst = ft_num(lst);
	if (!lst)
		return (0);
	return (lst);
}
