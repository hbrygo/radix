/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invert_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:51 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/15 18:30:35 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sa_without(t_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
}

static void	ft_sb_without(t_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
}

void	ft_sa(t_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	ft_printf("sa\n");
}

void	ft_sb(t_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	ft_printf("sb\n");
}

void	ft_ss(t_list *lst_a, t_list *lst_b)
{
	ft_sa_without(lst_a);
	ft_sb_without(lst_b);
	ft_printf("ss\n");
}
