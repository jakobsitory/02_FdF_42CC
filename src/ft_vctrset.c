/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectorset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:13:05 by jschott           #+#    #+#             */
/*   Updated: 2023/09/22 14:00:30 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	ft_vctrset(t_vector *vctr, float x, float y, float z)
{
	if (vctr)
	{
		vctr->x = x;
		vctr->y = y;
		vctr->z = z;
	}
}
