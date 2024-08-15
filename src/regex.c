/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:17 by jschott           #+#    #+#             */
/*   Updated: 2024/08/15 12:46:27 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Counts the number of valid numeric strings in an array.
 * 
 * @param argv The array of strings to be checked.
 * @return The count of valid numeric strings in the array, or 0 if any string is invalid.
 */
int	num_str(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while ((ft_issign(argv[i][j])))
				j++;
			while (argv[i][j] != '\0' && ft_strchr("0123456789", argv[i][j]))
				j++;
			if (argv[i][j] != '\0')
				return (0);
		}
		i++;
	}
	return (i);
}

/**
 * Reads a line from input, splits it into values, and adds them as vectors to a map.
 * 
 * @param map Pointer to the pointer of the first vector in the map.
 * @param input The input line to be processed.
 * @param y The y-coordinate for the vectors to be added.
 * @return The number of vectors added to the map, or 0 if an error occurs.
 */
int	read_line(t_vector **map, char *input, int y)
{
	char	*trimmed_input;
	char	**split_input;
	int		i;

	trimmed_input = ft_strtrim(input, "\n");
	free (input);
	split_input = ft_split(trimmed_input, ' ');
	free (trimmed_input);
	i = 0;
	if (ft_vctrsize(*map) != y * num_str(split_input))
	{
		while (split_input[i])
			free(split_input[i++]);
		free (split_input);
		ft_vctrclear(map, free);
		return (0);
	}
	while (split_input[i])
	{
		ft_vctradd_back(map, ft_vctrnew(i, y, ft_atol(split_input[i])));
		free (split_input[i++]);
	}
	free (split_input);
	return (i);
}

/**
 * Reads a file and creates a map of vectors from its contents.
 * 
 * @param fd The file descriptor of the file to be read.
 * @r
 */
t_vector	*read_file(int fd)
{
	char		*input;
	int			y;
	t_vector	*map;

	y = 0;
	map = 0;
	input = get_next_line (fd);
	while (input)
	{
		read_line (&map, input, y++);
		if (!map)
			break ;
		input = get_next_line (fd);
	}
	close (fd);
	if (!map)
	{
		return (fdf_errors(3));
	}
	return (map);
}

/**
 * Creates a map of points from a file.
 * 
 * @param file The name of the file to be processed.
 * @return A pointer to the first vector in the created map, or an error message if the operation fails.
 */
t_vector	*create_points(char *file)
{
	t_vector	*map;
	int			fd;

	if (!file)
		return (fdf_errors(0)); 
	if (!ft_strnstr(file, ".fdf", ft_strlen(file) + 1))
		return (fdf_errors(1));
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd(file, 2);
		return (fdf_errors(2));
	}
	map = read_file(fd);
	close (fd);
	return (map);
}
