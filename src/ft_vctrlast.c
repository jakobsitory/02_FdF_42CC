/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:51:51 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 10:14:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_vector	*ft_vctrlast(t_vector *pnt)
{
	if (!pnt)
		return (pnt);
	while (pnt->next)
		pnt = pnt->next;
	return (pnt);
}
