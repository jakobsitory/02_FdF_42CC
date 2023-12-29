/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:48 by jschott           #+#    #+#             */
/*   Updated: 2023/05/24 16:32:13 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			l_dest;
	size_t			l_src;

	l_dest = ft_strlen (dest);
	l_src = ft_strlen (src);
	j = 0;
	i = l_dest;
	if (size == 0 || size <= l_dest)
		return (size + l_src);
	while (src[j] != '\0' && j < size - l_dest - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (l_dest + l_src);
}
