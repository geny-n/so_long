/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:51:16 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/20 13:28:03 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_liste **lst, t_liste *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		new -> next = *lst;
		*lst = new;
	}
}
