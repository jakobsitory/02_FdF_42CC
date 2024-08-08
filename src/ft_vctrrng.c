/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrrng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:09 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:04:20 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Finds the largest absolute value between two floats.
 * 
 * @param a The first floating-point number.
 * @param b The second floating-point number.
 * @return The larger absolute value of `a` and `b`.
 */

float	bigger_abs(float a, float b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (b >= a)
		return (b);
	else
		return (a);
}

/**
 * Calculates the range of vector coordinates in a linked list.
 * 
 * @param pnt Pointer to the first vector in the linked list.
 * @return The largest absolute value among the minimum and maximum coordinates in the list.
 */
float	ft_vctrrng(t_vector *pnt)
{
	float	max;
	float	min;

	max = pnt->x;
	min = pnt->x;
	while (pnt)
	{
		if (pnt->x > max)
			max = pnt->x;
		if (pnt->x < min)
			min = pnt->x;
		if (pnt->y > max)
			max = pnt->y;
		if (pnt->y < min)
			min = pnt->y;
		if (pnt->z > max)
			max = pnt->z;
		if (pnt->z < min)
			min = pnt->z;
		pnt = pnt->next;
	}
	return (bigger_abs(min, max));
}
