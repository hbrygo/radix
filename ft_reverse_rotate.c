/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:04:44 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/09 15:20:46 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	temp2 = ft_lstlast(temp);
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	temp2->next = *lst;
	*lst = temp2;
	ft_printf("rra\n");
}

void	ft_rrb(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	temp2 = ft_lstlast(temp);
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	temp2->next = *lst;
	*lst = temp2;
	ft_printf("rrb\n");
}

void	ft_rrr(t_list *lst_a, t_list *lst_b)
{
	ft_rra(&lst_a);
	ft_rrb(&lst_b);
	ft_printf("rrr\n");
}
