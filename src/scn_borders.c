/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:58:11 by jschott           #+#    #+#             */
/*   Updated: 2023/09/22 17:23:18 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	vctr_get_center(t_vector *center, t_vector *min, t_vector *max)
{
	if (!center)
		center = ft_vctrnew(0, 0, 0);
	center->x = (min->x + max->x) / 2.0;
	center->y = (min->y + max->y) / 2.0;
	center->z = (min->z + max->z) / 2.0;
}

void	vctr_get_border(t_vector *vctr, t_vector *min, t_vector *max)
{
	t_vector	*ptr;

	ptr = vctr;
	if (!min)
		min = ft_vctrnew(0, 0, 0);
	if (!max)
		max = ft_vctrnew(0, 0, 0);
	while (ptr && min && max)
	{
		if (ptr->x > max->x)
			max->x = ptr->x;
		if (ptr->x < min->x)
			min->x = ptr->x;
		if (ptr->y > max->y)
			max->y = ptr->y;
		if (ptr->y < min->y)
			min->y = ptr->y;
		if (ptr->z > max->z)
			max->z = ptr->z;
		if (ptr->z < min->z)
			min->z = ptr->z;
		ptr = ptr->next;
	}
}

void	scn_update_borders(t_scene *scene)
{
	ft_vctrset(scene->center, 0.0, 0.0, 0.0);
	ft_vctrset(scene->min_vctr, 0.0, 0.0, 0.0);
	ft_vctrset(scene->max_vctr, 0.0, 0.0, 0.0);
	vctr_get_border(scene->map, scene->min_vctr, scene->max_vctr);
	vctr_get_center(scene->center, scene->min_vctr, scene->max_vctr);
}
