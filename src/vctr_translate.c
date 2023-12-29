/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:33:22 by jschott           #+#    #+#             */
/*   Updated: 2023/09/22 17:23:43 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	vctr_translate(t_vector *vctr, float x, float y, float z)
{
	t_vector	*ptr;

	ptr = vctr;
	while (ptr)
	{
		ptr->x += x;
		ptr->y += y;
		ptr->z += z;
		ptr = ptr->next;
	}
}

void	scn_translate(t_scene *scene, t_vector *trnslt)
{
	t_vector	*ptr;

	ptr = scene->map;
	while (ptr)
	{
		ptr->x -= trnslt->x;
		ptr->y -= trnslt->y;
		ptr->z -= trnslt->z;
		ptr = ptr->next;
	}
}
