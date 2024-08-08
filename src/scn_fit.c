/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_fit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:05:46 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:00:59 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Adjusts the zoom level of a scene to fit its frame within the display area.
 * 
 * Key steps in the function include:
 * - Creating new vectors `min` and `max` to store the minimum and maximum coordinates of the frame.
 * - Calling `vctr_get_border` to update `min` and `max` with the frame's border coordinates.
 * - Calculating the ranges `x_rng` and `y_rng` in the x and y dimensions, respectively.
 * - Adjusting the ranges to be positive values, if necessary.
 * - Comparing the aspect ratios of the scene's frame to the display area to determine the appropriate zoom level.
 * - The zoom level is set to ensure the frame fits within the display area, with a margin considered.
 * - Freeing the `min` and `max` vectors after their use.
 * 
 * @param scene Pointer to the `t_scene` structure whose zoom level is to be adjusted.
 */
void	scn_fit(t_scene *scene)
{
	float		x_rng;
	float		y_rng;
	t_vector	*min;
	t_vector	*max;

	min = ft_vctrnew(0, 0, 0);
	max = ft_vctrnew(0, 0, 0);
	vctr_get_border(scene->frame, min, max);
	x_rng = min->x - max->x;
	y_rng = min->y - max->y;
	if (x_rng < 0)
		x_rng *= -1;
	if (y_rng < 0)
		y_rng *= -1;
	if ((float) HEIGHT / y_rng < (float) WIDTH / x_rng)
		scene->zoom = (0.8 * (float) HEIGHT) / (y_rng * 0.5 * (float) HEIGHT);
	else
		scene->zoom = (0.8 * (float) WIDTH) / (x_rng * 0.5 * (float) HEIGHT);
	free (min);
	free (max);
}
