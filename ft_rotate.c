/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:03:45 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/11 10:26:14 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	temp2 = ft_lstlast(temp);
	*lst = temp->next;
	temp->next = NULL;
	temp2->next = temp;
	ft_printf("ra\n");
}

void	ft_rb(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	temp2 = ft_lstlast(temp);
	*lst = temp->next;
	temp->next = NULL;
	temp2->next = temp;
	ft_printf("rb\n");
}

void	ft_rr(t_list *lst_a, t_list *lst_b)
{
	ft_ra(&lst_a);
	ft_rb(&lst_b);
	ft_printf("rr\n");
}
