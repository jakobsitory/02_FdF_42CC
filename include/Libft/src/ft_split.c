/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:59:06 by jschott           #+#    #+#             */
/*   Updated: 2023/09/20 16:40:15 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words_in_str(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

void	ft_freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr)
		free(arr[i++]);
	free (arr);
}

char	*ft_writestr(char *pos, int len, char **words)
{
	char	*word;

	word = (char *) malloc (len + 1);
	if (word == NULL)
	{
		ft_freeall(words);
		return (NULL);
	}
	ft_strlcpy(word, pos, len + 1);
	return (word);
}

char	*ft_strnchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**words;
	int		wordlen;
	char	*pos;

	count = ft_words_in_str(s, c);
	words = (char **) ft_calloc (count + 1, sizeof(char *));
	if (!words)
		return (NULL);
	pos = (char *) s;
	i = 0;
	wordlen = 0;
	while (i + 1 <= count)
	{
		pos = ft_strnchr(&pos[wordlen], c);
		if (ft_strchr(pos, c))
			wordlen = ft_strchr(pos, c) - pos;
		else
			wordlen = ft_strlen(pos);
		words[i] = ft_writestr(pos, wordlen, words);
		i++;
	}
	words[count] = 0;
	return (words);
}
