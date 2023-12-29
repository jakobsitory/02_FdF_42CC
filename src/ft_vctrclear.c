/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:23:28 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 17:39:58 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	ft_vctrclear(t_vector **pnt, void (*del)(void*))
{
	t_vector	*tmp;

	if (pnt)
	{
		while (*pnt)
		{
			tmp = (*pnt)->next;
			ft_vctrdelone(*pnt, del);
			(*pnt) = tmp;
		}
	}
}
