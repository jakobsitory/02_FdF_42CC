/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_lines.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jschott <jschott@student.42berlin.de>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/08/28 12:04:56 by jschott		   #+#	#+#			 */
/*   Updated: 2023/09/20 17:12:52 by jschott		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../FdF.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && y <= HEIGHT && x <= WIDTH)
	{
		dst = data->addr + (y * data->line_length + \
							x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_bresenham(t_data *img, t_line *line)
{
	while (1)
	{
		my_mlx_pixel_put(img, line->p1_x, line->p1_y, line->color);
		if (line->p1_x == line->p2_x && line->p1_y == line->p2_y)
			break ;
		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			line->p1_x += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			line->p1_y += line->sy;
		}
	}
}

void	draw_line(t_data *img, t_vector *p1, t_vector *p2, int color)
{
	t_line	*line;

	line = (t_line *) malloc (sizeof(t_line));
	if (!line)
		return ;
	line->p1_x = (int) p1->x;
	line->p1_y = (int) p1->y;
	line->p2_x = (int) p2->x;
	line->p2_y = (int) p2->y;
	line->dx = ft_abs(line->p2_x - line->p1_x);
	line->dy = ft_abs(line->p2_y - line->p1_y);
	line->err = line->dx - line->dy;
	line->e2 = 2 * line->err;
	line->color = color;
	if (line->p1_x < line->p2_x)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->p1_y < line->p2_y)
		line->sy = 1;
	else
		line->sy = -1;
	draw_bresenham(img, line);
	free(line);
}
