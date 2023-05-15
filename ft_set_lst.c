/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:06:27 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/15 16:50:44 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_in_lst(int *tab, int size)
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

int	*ft_tri_tab(int	*tab, int size)
{
	int	i;
	int	*new_tab;
	int	j;
	int	higher;

	j = 0;
	higher = 0;
	new_tab = malloc(sizeof(int) * size);
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

t_list	*ft_num(t_list *lst)
{
	int		i;
	t_list	*return_lst;
	int		*tab;
	int		size;

	i = 0;
	size = ft_lstsize(lst);
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
	tab = ft_tri_tab(tab, size);
	return_lst = ft_in_lst(tab, size);
	return (return_lst);
}

void	ft_display(t_list *lst)
{
	ft_printf("\n");
	while (lst)
	{
		ft_printf("\ncontent: %d,", lst->content);
		ft_printf("partition: %d ", lst->partition);
		lst = lst->next;
	}
	ft_printf("\n");
}

t_list	*ft_set_lst(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
	{
		lst = NULL;
		lst = ft_lstsplit(argv[1]);
		return (lst);
	}
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
