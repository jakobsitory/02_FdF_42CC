/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:11 by jschott           #+#    #+#             */
/*   Updated: 2023/05/24 16:32:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*cdest;
	const char	*csrc;

	cdest = (char *) dest;
	csrc = (const char *) src;
	i = 0;
	if (!src && !dest)
		return (dest);
	while (i < (int) n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return ((void *) cdest);
}
