/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:38:43 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:00:42 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Initializes a scene with a given map of vectors.
 * 
 * Key steps in the initialization process include:
 * - Allocating memory for the `t_scene` structure.
 * - Setting the `map` field to the provided map of vectors.
 * - Initializing vector fields (`max_vctr`, `min_vctr`, `center`, `rotation`, `translate`) with default values.
 * - Calculating the scene's width and height based on the map.
 * - Setting the default zoom level and projection mode.
 * - Normalizing the scene using `scn_normalize`.
 * 
 * If any of the vector fields fail to initialize, the function calls `scn_dstr` to destroy the scene and free
 * allocated resources before returning NULL.
 * 
 * @param map Pointer to the first vector in the linked list representing the map of vectors.
 * @return Pointer to the initialized `t_scene` structure, or NULL if initialization fails.
 */
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

/**
 * Destroys a scene and frees allocated resources.
 * 
 * @param scene Pointer to the `t_scene` structure to be destroyed.
 */
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
