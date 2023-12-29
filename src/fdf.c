/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:43:49 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 09:19:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

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
