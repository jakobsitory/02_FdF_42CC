/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:02:41 by jschott           #+#    #+#             */
/*   Updated: 2023/05/24 16:32:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joinstr;
	long int	joinlen;

	joinlen = (ft_strlen(s1) + ft_strlen(s2));
	joinstr = (char *) malloc (joinlen + 1);
	if (joinstr == NULL)
		return (NULL);
	ft_strlcpy(joinstr, s1, joinlen + 1);
	ft_strlcat(joinstr, s2, joinlen + 1);
	return (joinstr);
}
