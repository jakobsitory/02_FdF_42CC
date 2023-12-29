/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:12:18 by jschott           #+#    #+#             */
/*   Updated: 2023/05/25 17:09:48 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if ((long int) len < 0)
		len = ft_strlen(s);
	if ((long int) len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *) malloc ((unsigned long int)len + 1);
	if (substr == NULL)
		return (NULL);
	if (!s || len <= 0 || start >= (unsigned int) ft_strlen(s))
	{
		free(substr);
		substr = ft_strdup("\0");
		return (substr);
	}
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
