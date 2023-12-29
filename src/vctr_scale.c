/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:37:38 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 09:23:53 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

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
