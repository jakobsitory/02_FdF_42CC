/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrrng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:09 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 14:04:52 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

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
