/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:05:01 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 10:19:24 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	rotate_x(t_vector *input, float angle_degr)
{
	float	prev_y;
	float	prev_z;
	float	angle_rad;

	angle_rad = degr_to_rad(angle_degr);
	prev_y = input->y;
	prev_z = input->z;
	input->y = prev_y * cos(angle_rad) + prev_z * sin(angle_rad);
	input->z = prev_y * -sin(angle_rad) + prev_z * cos(angle_rad);
}

void	rotate_y(t_vector *input, float angle_degr)
{
	float	prev_x;
	float	prev_z;
	float	angle_rad;

	angle_rad = degr_to_rad(angle_degr);
	prev_x = input->x;
	prev_z = input->z;
	input->x = prev_x * cos(angle_rad) + prev_z * sin(angle_rad);
	input->z = prev_x * -sin(angle_rad) + prev_z * cos(angle_rad);
}

void	rotate_z(t_vector *input, float angle_degr)
{
	float	prev_x;
	float	prev_y;
	float	angle_rad;

	angle_rad = degr_to_rad(angle_degr);
	prev_x = input->x;
	prev_y = input->y;
	input->x = prev_x * cos(angle_rad) - prev_y * sin(angle_rad);
	input->y = prev_x * sin(angle_rad) + prev_y * cos(angle_rad);
}

void	vctr_rotate(t_vector *vctr, t_vector *rotation)
{
	t_vector	*pntr;

	pntr = vctr;
	while (pntr)
	{
		rotate_x(pntr, rotation->x);
		rotate_y(pntr, rotation->y);
		rotate_z(pntr, rotation->z);
		pntr = pntr->next;
	}
}
