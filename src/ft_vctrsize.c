/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:09 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 16:56:21 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	ft_vctrsize(t_vector *vctr)
{
	int	count;

	count = 0;
	if (!vctr)
		return (0);
	count++;
	if (vctr->next != NULL)
		count = count + ft_vctrsize(vctr->next);
	return (count);
}
