/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:36:55 by jschott           #+#    #+#             */
/*   Updated: 2023/05/31 15:46:29 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newlstel;

	if (!f || !lst || !del)
		return (NULL);
	newlstel = ft_lstnew(f(lst->content));
	if (!newlstel)
	{
		del(newlstel->content);
		return (NULL);
	}
	newlst = newlstel;
	lst = lst->next;
	while (lst)
	{
		newlstel = ft_lstnew(f(lst->content));
		if (!newlstel)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newlstel);
		lst = lst->next;
	}
	return (newlst);
}
