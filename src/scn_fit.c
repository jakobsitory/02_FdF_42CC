/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_fit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:05:46 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 10:14:45 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

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
