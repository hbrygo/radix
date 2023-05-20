/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:26:08 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/19 18:19:19 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

//Fonction qui supprime tout une liste chainee