/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctradd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:37 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:05:36 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Adds a new vector to the end of a linked list of vectors.
 * 
 * @param vctr Pointer to the pointer of the first vector in the linked list. This may be modified if the list is
 *             initially empty.
 * @param new Pointer to the new vector to be added to the list.
 */
void	ft_vctradd_back(t_vector **vctr, t_vector *new)
{
	t_vector	*pos;

	if (!*vctr)
	{
		*vctr = new;
		return ;
	}
	pos = ft_vctrlast(*vctr);
	pos->next = new;
}
