/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:37 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/20 13:27:46 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstnew(void *content)
{
	t_liste	*newlst;

	newlst = malloc(sizeof(t_liste));
	if (newlst == NULL)
		return (NULL);
	newlst -> content = content;
	newlst -> next = NULL;
	return (newlst);
}
