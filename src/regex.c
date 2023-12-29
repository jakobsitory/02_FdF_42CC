/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:40:17 by jschott           #+#    #+#             */
/*   Updated: 2023/11/17 12:47:37 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

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
