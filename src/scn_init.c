/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:38:43 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 09:32:18 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_scene	*scn_init(t_vector *map)
{
	static t_scene	*scene;

	scene = (t_scene *) malloc (sizeof(t_scene));
	if (!scene)
		return (0);
	scene->map = map;
	scene->max_vctr = ft_vctrnew(0, 0, 0);
	scene->min_vctr = ft_vctrnew(0, 0, 0);
	scene->center = ft_vctrnew(0, 0, 0);
	scene->rotation = ft_vctrnew(0, 0, 0);
	scene->translate = ft_vctrnew(0, 0, 0);
	if (!(scene->map || scene->max_vctr || scene->translate || \
			scene->min_vctr || scene->center || scene->rotation))
	{
		scn_dstr(scene);
		return (0);
	}
	scene->width = (float) elem_in_line(&map);
	scene->height = (float) ft_vctrsize(map) / scene->width;
	scene->frame = 0;
	scene->window = 0;
	scene->zoom = 0.6;
	scene->projection = PROJECT_ISO;
	scn_normalize (scene);
	return (scene);
}

void	scn_dstr(t_scene *scene)
{
	ft_vctrclear (&scene->map, free);
	ft_vctrclear (&scene->rotation, free);
	ft_vctrclear (&scene->center, free);
	ft_vctrclear (&scene->max_vctr, free);
	ft_vctrclear (&scene->min_vctr, free);
	ft_vctrclear (&scene->frame, free);
	ft_vctrclear (&scene->translate, free);
	mlx_destroy_image(scene->window->mlx, scene->img->img);
	mlx_destroy_window(scene->window->mlx, scene->window->mlx_win);
	mlx_destroy_display(scene->window->mlx);
	free (scene->window->mlx);
	free (scene->window);
	free (scene->img);
	free (scene);
}
