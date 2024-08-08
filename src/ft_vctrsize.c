/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:09 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:03:47 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Counts the number of elements in a linked list of vectors.
 * 
 * @param vctr Pointer to the first element of the linked list of vectors.
 * @return The total number of elements in the linked list.
 */
int	ft_vctrsize(t_vector *vctr)
{
	int	count;

	count = 0;
	if (!vctr)
		return (0);
	count++;
	if (vctr->next != NULL)
		count = count + ft_vctrsize(vctr->next);
	return (count);
}
