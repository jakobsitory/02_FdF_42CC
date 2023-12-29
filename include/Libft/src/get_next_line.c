/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:02 by jschott           #+#    #+#             */
/*   Updated: 2023/09/28 09:10:59 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*shorten(char *line)
{
	char	*rest;
	int		rest_len;

	rest = NULL;
	if (!ft_strchr(line, '\n') || ft_strlen(line) == 1)
	{
		free (line);
		return (NULL);
	}
	if (0 == ft_strchr(line, '\n') - line - ft_strlen(line) + 1)
	{
		free (line);
		return (NULL);
	}
	rest_len = ft_strlen(ft_strchr(line, '\n'));
	rest = (char *) malloc (rest_len + 1);
	if (!rest)
		return (NULL);
	ft_strlcpy(rest, ft_strchr(line, '\n') + 1, rest_len);
	free (line);
	return (rest);
}

char	*extract(char *line)
{
	char	*result;

	result = NULL;
	if (!ft_strchr(line, '\n') || (ft_strlen(line) == 1 && BUFFER_SIZE > 1))
	{
		result = (char *) malloc (ft_strlen(line) + 1);
		if (!result)
			return (NULL);
		ft_strlcpy(result, line, ft_strlen(line) + 1);
	}
	else
	{
		result = (char *) malloc (ft_strchr(line, '\n') - line + 2);
		if (!result)
			return (NULL);
		ft_strlcpy(result, line, ft_strchr(line, '\n') - line + 2);
	}
	return (result);
}

char	*al_helper(int fd, int *r_len, char *line, char *buffer)
{
	char	*new_line;

	if (!line)
	{
		line = (char *) malloc (1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	while ((*r_len) > 0)
	{
		buffer[(*r_len)] = '\0';
		new_line = ft_strjoin(line, buffer);
		free (line);
		if (ft_strchr(new_line, '\n'))
			break ;
		line = new_line;
		(*r_len) = read(fd, buffer, BUFFER_SIZE);
	}
	return (new_line);
}

char	*add_line(int fd, int *r_len, char *line)
{
	char	*buffer;
	char	*new_line;

	new_line = 0;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	(*r_len) = read(fd, buffer, BUFFER_SIZE);
	if ((*r_len) == 0)
		new_line = line;
	else if ((*r_len) > 0)
		new_line = al_helper(fd, r_len, line, buffer);
	if ((*r_len) < 0)
	{
		free (line);
		free (new_line);
		free (buffer);
		return (NULL);
	}
	free(buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			*r_len;
	int			read_len;
	char		*result;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_len = &read_len;
	read_len = 1;
	if (!line || !ft_strchr(line, '\n'))
		line = add_line(fd, r_len, line);
	if (line && read_len >= 0)
	{
		result = extract(line);
		line = shorten(line);
	}
	else if (read_len < 0)
		free (line);
	return (result);
}
