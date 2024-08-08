/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:33:22 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:57:35 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Translates a linked list of vectors by a specified amount.
 * 
 * @param vctr Pointer to the first vector in the linked list to be translated.
 * @param x The amount to translate each vector along the x-axis.
 * @param y The amount to translate each vector along the y-axis.
 * @param z The amount to translate each vector along the z-axis.
 */
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

/**
 * Translates all vectors in a scene by the inverse of a specified vector.
 * 
 * @param scene Pointer to the scene structure containing the map of vectors to be translated.
 * @param trnslt Pointer to the vector specifying the amounts to translate the scene by, in the inverse direction.
 */
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
