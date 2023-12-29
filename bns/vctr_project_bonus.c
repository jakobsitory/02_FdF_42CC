/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_project_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:03:49 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 10:19:24 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

float	degr_to_rad(int degrees)
{
	return (degrees * (M_PI / 180));
}

t_vector	*parallel(t_vector *vctr)
{
	float		vctr_x;
	float		vctr_y;
	float		vctr_z;

	vctr_x = vctr->x;
	vctr_y = vctr->y;
	vctr_z = vctr->z;
	return (ft_vctrnew(vctr_x - vctr_z * cos(degr_to_rad(45)), \
						vctr_y - vctr_z * sin(degr_to_rad(45)), \
						0.0));
}

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

void	project(t_scene *scene)
{
	t_vector	*pntr;

	pntr = scene->map;
	ft_vctrclear(&scene->frame, free);
	while (pntr && scene->projection == PROJECT_PARALLEL)
	{
		ft_vctradd_back(&scene->frame, parallel (pntr));
		pntr = pntr->next;
	}
	while (pntr && scene->projection == PROJECT_ISO)
	{
		ft_vctradd_back(&scene->frame, isometric (pntr));
		pntr = pntr->next;
	}
}
