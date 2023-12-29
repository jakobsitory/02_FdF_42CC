/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctradd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:37 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 10:14:01 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	ft_vctradd_back(t_vector **vctr, t_vector *new)
{
	t_vector	*pos;

	if (!*vctr)
	{
		*vctr = new;
		return ;
	}
	pos = ft_vctrlast(*vctr);
	pos->next = new;
}
