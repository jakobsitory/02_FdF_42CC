/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:03:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:59:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Converts degrees to radians.
 * 
 * @param degrees The angle in degrees to be converted.
 * @return The angle converted to radians.
 */
float	degr_to_rad(int degrees)
{
	return (degrees * (M_PI / 180));
}

/**
 * Applies isometric projection to a vector.
 * 
 * @param vctr Pointer to the vector to be projected.
 * @return A new vector representing the isometric projection of the input vector.
 */
t_vector	*isometric(t_vector *vctr)
{
	float		vctr_x;
	float		vctr_y;
	float		vctr_z;
	float		angle_rad;

	angle_rad = degr_to_rad(30);
	vctr_x = vctr->x;
	vctr_y = vctr->y;
	vctr_z = vctr->z;
	return (ft_vctrnew((vctr_x - vctr_y) * cos(angle_rad), \
						-vctr_z + (vctr_x + vctr_y) * sin(angle_rad), \
						0.0));
}

/**
 * Projects all vectors in a scene using isometric projection.
 * 
 * @param scene Pointer to the scene structure containing the map of vectors to be projected.
 */
void	project(t_scene *scene)
{
	t_vector	*pntr;

	pntr = scene->map;
	ft_vctrclear(&scene->frame, free);
	while (pntr && scene->projection == PROJECT_ISO)
	{
		ft_vctradd_back(&scene->frame, isometric (pntr));
		pntr = pntr->next;
	}
}
