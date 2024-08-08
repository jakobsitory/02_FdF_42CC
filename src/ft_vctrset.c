/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:13:05 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:03:58 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Sets the coordinates of a vector.
 * 
 * @param vctr Pointer to the `t_vector` structure to be updated.
 * @param x The new x-coordinate for the vector.
 * @param y The new y-coordinate for the vector.
 * @param z The new z-coordinate for the vector.
 */
void	ft_vctrset(t_vector *vctr, float x, float y, float z)
{
	if (vctr)
	{
		vctr->x = x;
		vctr->y = y;
		vctr->z = z;
	}
}
