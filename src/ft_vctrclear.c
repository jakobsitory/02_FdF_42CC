/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:23:28 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:05:22 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Frees and clears the entire linked list of vectors.
 * 
 * @param pnt Pointer to the pointer of the first vector in the linked list. This pointer is modified to point to
 *            NULL after clearing the list.
 * @param del Function pointer to the function used to free the vector's associated data.
 */
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
