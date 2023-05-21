/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:32:43 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/21 11:22:50 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_list
{
	long int		content;
	struct s_list	*next;
}				t_list;

void		*ft_set_lst(int argc, char **argv);
int			main(int argc, char **argv);
void		ft_sa(t_list *lst);
void		ft_sb(t_list *lst);
void		ft_ss(t_list *lst_a, t_list *lst_b);
void		ft_pa(t_list **lst_a, t_list **lst_b);
void		ft_pb(t_list **lst_a, t_list **lst_b);
void		ft_rra(t_list **lst);
void		ft_rrb(t_list **lst);
void		ft_rrr(t_list *lst_a, t_list *lst_b);
void		ft_ra(t_list **lst);
void		ft_rb(t_list **lst);
void		ft_rr(t_list *lst_a, t_list *lst_b);
void		ft_display(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(long int content);
int			ft_lstsize(t_list *lst);
long int	ft_atoi(char *str);
int			ft_issort(t_list *lst);
int			ft_special(t_list **lst_a, t_list **lst_b);
int			ft_threesort(t_list **lst_a);
int			ft_foursort(t_list **lst_a, t_list **lst_b);
int			ft_fivesort(t_list **lst_a, t_list **lst_b);
void		ft_rrb_without(t_list **lst);
void		ft_rra_without(t_list **lst);
void		ft_rb_without(t_list **lst);
void		ft_ra_without(t_list **lst);
int			ft_check(long int *tab, int size);
void		*ft_error(void);
void		ft_lstclear(t_list *lst);

#endif