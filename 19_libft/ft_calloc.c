/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:11:20 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/11 20:07:52 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}

//Fonction qui alloue une memoire de nmemb charactere de type size