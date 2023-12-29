/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 10:28:08 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	win_close(t_window *window)
{
	mlx_loop_end (window->mlx);
	return (0);
}

void	img_update(t_scene *scene)
{
	void	*img_new;
	t_data	*img_temp;

	img_new = img_init(scene);
	img_temp = scene->img;
	vctr_scale(scene->frame, scene->zoom);
	vctr_translate(scene->frame, \
					0.5 * (float) WIDTH + scene->translate->x, \
					0.5 * (float) HEIGHT + scene->translate->y, \
					0);
	vctr_draw(img_new, scene->frame);
	scene->img = img_new;
	mlx_put_image_to_window(scene->window->mlx, \
							scene->window->mlx_win, scene->img->img, 0, 0);
	mlx_destroy_image(scene->window->mlx, img_temp->img);
	free (img_temp);
}

void	change_angle(t_scene *scene, int direction)
{
	if (direction == ARROW_LEFT)
		scene->rotation->z += 1;
	if (direction == ARROW_RIGHT)
		scene->rotation->z -= 1;
	if (direction == ARROW_UP || direction == ARROW_DOWN)
	{
		scene->rotation->y += direction - ARROW_UP - 1;
		scene->rotation->x += direction - ARROW_UP - 1;
	}
	vctr_rotate(scene->map, scene->rotation);
	ft_vctrset(scene->rotation, 0, 0, 0);
	project(scene);
	img_update(scene);
}

int	keypress(int keycode, t_scene *scene)
{
	t_window	*window;

	window = scene->window;
	if (keycode == ESCAPE)
		return (win_close (window));
	if (keycode >= 54361 && keycode <= 65365)
		change_angle(scene, keycode);
	if (keycode == 65451)
		scene->zoom += 0.01;
	if (keycode == 65453 && scene->zoom >= 0.01)
		scene->zoom -= 0.01;
	if (keycode == PROJECT_PARALLEL || keycode == PROJECT_ISO)
		scene->projection = keycode;
	if (TRANS_LEFT == keycode || TRANS_RIGHT == keycode)
		vctr_translate(scene->translate, 10 * (keycode - TRANS_LEFT - 1), 0, 0);
	if (TRANS_UP == keycode || TRANS_DOWN == keycode)
		vctr_translate(scene->translate, 0, 10 * (keycode - TRANS_UP - 1), 0);
	if (65437 == keycode)
		ft_vctrset(scene->translate, 0, 0, 0);
	change_angle(scene, 0);
	return (0);
}

void	key_events(t_scene *scene)
{
	mlx_hook(scene->window->mlx_win, 17, 1L << 0, win_close, scene->window);
	mlx_hook(scene->window->mlx_win, 2, 1L << 0, keypress, scene);
}
