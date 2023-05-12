/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:02:01 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/09 16:24:50 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp->next = NULL;
	ft_lstadd_front(lst_b, temp);
	ft_printf("pb\n");
}

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	temp->next = NULL;
	ft_lstadd_front(lst_a, temp);
	ft_printf("pa\n");
}
