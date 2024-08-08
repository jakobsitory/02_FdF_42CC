/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:43:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:06:50 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Counts the number of elements in the first line of a map.
 * 
 * The function `elem_in_line` calculates the number of `t_vector` elements that are in the first line (row) of a
 * map. It iterates through the linked list of vectors, starting from the first vector, and counts the elements
 * until it encounters a vector that either does not have a `next` vector or has a different `y` value (indicating
 * a new row). This function is useful for determining the width of the map in terms of vector elements.
 * 
 * @param map Pointer to the pointer of the first vector in the linked list representing the map.
 * @return The number of elements in the first line of the map, or 0 if the map is empty.
 */
int	elem_in_line(t_vector **map)
{
	int			i;
	t_vector	*ptr;

	if (!(*map))
		return (0);
	i = 1;
	ptr = (*map);
	while (ptr->next && ptr->y == ptr->next->y)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

/**
 * Initializes an image structure for rendering.
 * 
 * The function `img_init` allocates and initializes a `t_data` structure, which is used to store image data for
 * rendering. It sets up the image with the `mlx_new_image` function, using the width and height defined by the
 * `scene` parameters. It also initializes the image's line length, color depth (bits per pixel), and endianness
 * using `mlx_get_data_addr`. This function is essential for preparing the image buffer where the scene will be
 * drawn.
 * 
 * @param scene Pointer to the `t_scene` structure containing window and rendering information.
 * @return A pointer to the initialized `t_data` structure, or NULL if memory allocation fails.
 */
t_data	*img_init(t_scene *scene)
{
	static t_data		*img;

	img = (t_data *) malloc (sizeof(t_data));
	if (!img)
		return (0);
	img->img = mlx_new_image(scene->window->mlx, WIDTH, HEIGHT);
	img->line_length = 100;
	img->cols = scene->width;
	img->rows = scene->height;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
	return (img);
}

/**
 * Initializes the window for the scene.
 * 
 * The function `win_init` creates and initializes a `t_window` structure, which includes setting up the
 * MiniLibX window with `mlx_new_window` and initializing the MiniLibX instance with `mlx_init`. It also calls
 * `img_init` to prepare the image structure for rendering. This function is crucial for setting up the graphical
 * window where the scene will be displayed.
 * 
 * @param scene Pointer to the `t_scene` structure containing scene information.
 * @return A pointer to the initialized `t_window` structure, or NULL if memory allocation fails.
 */
t_window	*win_init(t_scene *scene)
{
	t_window			*window;

	window = (t_window *) malloc (sizeof(t_window));
	if (!window)
		return (0);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Fil de Fer");
	scene->window = window;
	scene->img = img_init(scene);
	return (window);
}

/**
 * Renders the scene.
 * 
 * The function `draw_scn` orchestrates the rendering of the scene. It initializes the window and image structures,
 * applies projections and transformations to fit the scene within the frame, and draws the vectors onto the image
 * buffer. Finally, it displays the image in the window and enters the main event loop to handle user interactions.
 * This function is the main entry point for rendering the scene.
 * 
 * @param scene Pointer to the `t_scene` structure containing all the information needed to render the scene.
 * @return Always returns 1, indicating successful execution.
 */
int	draw_scn(t_scene *scene)
{
	t_window	*window;

	window = win_init(scene);
	project(scene);
	scn_fit(scene);
	vctr_scale(scene->frame, scene->zoom);
	vctr_translate(scene->frame, 0.5 * (float) WIDTH, 0.5 * (float) HEIGHT, 0);
	vctr_draw(scene->img, scene->frame);
	mlx_put_image_to_window(window->mlx, window->mlx_win, \
							scene->img->img, 0, 0);
	key_events(scene);
	mlx_loop(window->mlx);
	return (1);
}

/**
 * The main function of the program.
 * 
 * This function serves as the entry point for the program. It processes command-line arguments to load a map and
 * initializes the scene. If the map is successfully created and the scene is initialized, it proceeds to render
 * the scene and then destroys the scene resources upon completion. This function handles the overall flow of the
 * program, from initialization to cleanup.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @return Returns 1 on successful execution or -1 if an error occurs during map creation.
 */
int	main(int argc, char **argv)
{
	t_vector		*map;
	static t_scene	*scene;

	if (argc > 2)
		map = fdf_errors(4);
	else
		map = create_points(argv[1]);
	if (!map)
		return (-1);
	scene = scn_init (map);
	if (scene)
	{
		draw_scn(scene);
		scn_dstr(scene);
	}
	return (1);
}
