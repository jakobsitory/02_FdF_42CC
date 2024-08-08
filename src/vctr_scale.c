/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:37:38 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:58:19 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Scales a linked list of vectors by a specified zoom factor.
 * 
 * @param vctr Pointer to the first vector in the linked list to be scaled.
 * @param zoom The zoom factor by which to scale the vectors.
 */
void	vctr_scale(t_vector *vctr, float zoom)
{
	float		zoom_pxl;
	t_vector	*pntr;

	pntr = vctr;
	zoom_pxl = zoom * 0.5 * (float) HEIGHT;
	while (pntr)
	{
		pntr->x *= zoom_pxl;
		pntr->y *= zoom_pxl;
		pntr->z *= zoom_pxl;
		pntr = pntr->next;
	}
}
