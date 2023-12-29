/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:31:34 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 10:50:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_vector	*ft_vctrnew(float x, float y, float z)
{
	t_vector	*vctr;

	vctr = (t_vector *) malloc (sizeof(t_vector));
	if (!vctr)
		return (0);
	vctr->x = x;
	vctr->y = y;
	vctr->z = z;
	vctr->a = 1.0;
	vctr->next = 0;
	return (vctr);
}
