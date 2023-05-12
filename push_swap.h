/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:32:43 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/12 12:52:16 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "19_libft/libft.h"
# include <stdlib.h>

t_list	*ft_set_lst(int argc, char **argv);
int		main(int argc, char **argv);
void	ft_sa(t_list *lst);
void	ft_sb(t_list *lst);
void	ft_ss(t_list *lst_a, t_list *lst_b);
void	ft_pa(t_list **lst_a, t_list **lst_b);
void	ft_pb(t_list **lst_a, t_list **lst_b);
void	ft_rra(t_list **lst);
void	ft_rrb(t_list **lst);
void	ft_rrr(t_list *lst_a, t_list *lst_b);
void	ft_ra(t_list **lst);
void	ft_rb(t_list **lst);
void	ft_rr(t_list *lst_a, t_list *lst_b);
int		ft_middle(t_list *lst);
void	*ft_lstsplit(char *str);
void	ft_last_part(t_list **lst_a, t_list **lst_b, int next);
void	ft_display(t_list *lst);
int		ft_middle2(t_list *lst);
int		ft_higher(t_list *lst, int previous);
void	ft_suite(t_list **lst_a, t_list **lst_b);
void	ft_tri(t_list **lst_a, t_list **lst_b, int next);
void	ft_end(t_list **lst_a, t_list **lst_b, int last);
int		ft_lstsize2(t_list *lst);
void	ft_suite2(t_list **lst_a, t_list **lst_b);
int		ft_tri2(t_list **lst_a, t_list **lst_b, int next);

#endif