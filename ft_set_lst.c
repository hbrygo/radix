/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:06:27 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/19 12:08:59 by hubrygo          ###   ########.fr       */
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
	return (new_tab);
}

void	*ft_num(t_list *lst)
{
	int			i;
	t_list		*return_lst;
	long int	*tab;
	int			size;

	i = 0;
	size = ft_lstsize(lst);
	tab = malloc(sizeof(long int) * size);
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
	if (ft_check(tab, size) == 0)
		return (ft_error());
	tab = ft_tri_tab(tab, size);
	return_lst = ft_in_lst(tab, size);
	return (return_lst);
}
void	*ft_set_lst(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	lst = NULL;
	if (argc == 1)
		return (NULL);
	if (argc == 2)
		return (ft_lstsplit(argv[1]));
	else
		lst = ft_lstnew(ft_atoi(argv[1]));
	i = 1;
	while (++i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&lst, temp);
	}
	lst = ft_num(lst);
	return (lst);
}
