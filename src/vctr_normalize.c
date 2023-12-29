/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:28:33 by jschott           #+#    #+#             */
/*   Updated: 2023/09/26 13:23:14 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

float	biggest_of_three(float one, float two, float three)
{
	if (one >= two && one >= three)
		return (one);
	if (two >= one && two >= three)
		return (two);
	return (three);
}

void	vctr_normalize(t_vector *vctr, t_vector *min, t_vector *max)
{
	t_vector	*ptr;
	float		x_max;
	float		y_max;
	float		z_max;
	float		scale;

	x_max = bigger_abs(min->x, max->x);
	y_max = bigger_abs(min->y, max->y);
	z_max = bigger_abs(min->z, max->z);
	scale = biggest_of_three(x_max, y_max, z_max);
	ptr = vctr;
	while (ptr && scale != 0)
	{
		ptr->x /= scale;
		ptr->y /= scale;
		ptr->z /= scale;
		ptr = ptr->next;
	}
}

void	scn_normalize(t_scene *scene)
{
	t_vector	*ptr;
	float		x_max;
	float		y_max;
	float		z_max;
	float		scale;

	scn_update_borders(scene);
	scn_translate (scene, scene->center);
	x_max = bigger_abs(scene->min_vctr->x, scene->max_vctr->x);
	y_max = bigger_abs(scene->min_vctr->y, scene->max_vctr->y);
	z_max = bigger_abs(scene->min_vctr->z, scene->max_vctr->z);
	scale = biggest_of_three(x_max, y_max, z_max);
	ptr = scene->map;
	while (ptr && scale != 0)
	{
		ptr->x /= scale;
		ptr->y /= scale;
		ptr->z /= scale;
		ptr = ptr->next;
	}
	scn_update_borders(scene);
}
