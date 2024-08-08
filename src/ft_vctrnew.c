/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:31:34 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:04:37 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Allocates and initializes a new vector.
 * 
 * @param x The x-coordinate for the new vector.
 * @param y The y-coordinate for the new vector.
 * @param z The z-coordinate for the new vector.
 * @return A pointer to the newly allocated and initialized vector, or NULL if memory allocation fails.
 */
t_vector	*ft_vctrnew(float x, float y, float z)
{
	t_vector	*vctr;

	vctr = (t_vector *) malloc (sizeof(t_vector));
	if (!vctr)
		return (0);
	vctr->x = x;
	vctr->y = y;
	vctr->z = z;
	vctr->a = 1.0;
	vctr->next = 0;
	return (vctr);
}
