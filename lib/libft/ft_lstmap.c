/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:58:42 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/20 13:32:34 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstmap(t_liste *lst, void *(*f)(void *), void (*del)(void *))
{
	t_liste	*lst_origine;
	void	*temp;
	t_liste	*lst_new;

	lst_origine = 0;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst)
	{
		temp = f(lst -> content);
		lst_new = ft_lstnew(temp);
		if (!lst_new)
		{
			ft_lstclear(&lst_new, (*del));
			return (0);
		}
		ft_lstadd_back (&lst_origine, lst_new);
		lst = lst -> next;
	}
	return (lst_origine);
}
