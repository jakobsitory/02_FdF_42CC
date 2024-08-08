/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:51:51 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:04:49 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Finds the last vector in a linked list.
 * 
 * @param pnt Pointer to the first vector in the linked list.
 * @return A pointer to the last vector in the list, or NULL if the list is empty or `pnt` is NULL.
 */
t_vector	*ft_vctrlast(t_vector *pnt)
{
	if (!pnt)
		return (pnt);
	while (pnt->next)
		pnt = pnt->next;
	return (pnt);
}
