/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:25 by jschott           #+#    #+#             */
/*   Updated: 2023/05/24 16:32:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*cdest;
	const char	*csrc;

	i = 0;
	cdest = (char *) dest;
	csrc = (const char *) src;
	if (cdest <= csrc && (src || dest))
	{
		while (i < (int) n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else if (src || dest)
	{
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	}
	return (dest);
}
