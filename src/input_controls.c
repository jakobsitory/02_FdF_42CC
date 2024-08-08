/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:03:30 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Closes the window and ends the event loop.
 * 
 * @param window Pointer to the `t_window` structure representing the window to be closed.
 * @return Always returns 0, indicating successful execution.
 */
int	win_close(t_window *window)
{
	mlx_loop_end (window->mlx);
	return (0);
}

/**
 * Handles key press events for the scene.
 * 
 * @param keycode The keycode of the pressed key.
 * @param scene Pointer to the `t_scene` structure representing the current scene.
 * @return Returns 0 if the window is requested to close, otherwise returns 0 by default.
 */
int	keypress(int keycode, t_scene *scene)
{
	t_window	*window;

	window = scene->window;
	if (keycode == ESCAPE)
		return (win_close (window));
	return (0);
}

/**
 * Registers key event handlers for the scene.
 * 
 * @param scene Pointer to the `t_scene` structure for which key events are being registered.
 */
void	key_events(t_scene *scene)
{
	mlx_hook(scene->window->mlx_win, 17, 1L << 0, win_close, scene->window);
	mlx_hook(scene->window->mlx_win, 2, 1L << 0, keypress, scene);
}
