/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:20:08 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:00:00 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Draws lines between vectors in a grid.
 * 
 * @param img Pointer to the `t_data` structure containing image data.
 * @param vctr Pointer to the first `t_vector` in the linked list of vectors.
 */
void	vctr_draw(t_data *img, t_vector *vctr)
{
	int			i;
	t_vector	*vctr_hrztl;
	t_vector	*vctr_vrtcl;

	i = 0;
	vctr_hrztl = vctr;
	vctr_vrtcl = vctr;
	while (i++ < (*img).cols)
		vctr_vrtcl = vctr_vrtcl->next;
	i = 1;
	while (vctr_hrztl)
	{
		if (i % (*img).cols != 0 && vctr_hrztl->next)
			draw_line(img, vctr_hrztl, vctr_hrztl->next, 0x00FF5733);
		if (vctr_vrtcl)
		{
			draw_line(img, vctr_hrztl, vctr_vrtcl, 0x00E389B9);
			vctr_vrtcl = vctr_vrtcl->next;
		}
		vctr_hrztl = vctr_hrztl->next;
		i++;
	}
}
