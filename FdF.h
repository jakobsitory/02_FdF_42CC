/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:44:25 by jschott           #+#    #+#             */
/*   Updated: 2023/10/02 09:17:39 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "include/Libft/include/libft.h"
# include "include/Libft/include/get_next_line.h"
# include "include/Libft/include/ft_printf.h"

# define WIDTH 1024
# define HEIGHT 768

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define MINUS 65453
# define PLUS 65451
# define ESCAPE 65307
# define PROJECT_PARALLEL 112
# define PROJECT_ISO 105

# define TRANS_LEFT 65430
# define TRANS_RIGHT 65432
# define TRANS_UP 65431
# define TRANS_DOWN 65433

typedef struct s_data {
	void	*img;
	void	*next_image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		cols;
	int		rows;
	int		endian;
}			t_data;

typedef struct s_window {
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}			t_window;

typedef struct s_scene {
	int				width;
	int				height;
	float			zoom;
	struct s_window	*window;
	struct s_data	*img;
	struct s_vector	*center;
	struct s_vector	*rotation;
	struct s_vector	*min_vctr;
	struct s_vector	*max_vctr;
	struct s_vector	*map;
	struct s_vector	*frame;
	struct s_vector	*translate;
	int				projection;
	int				act_frame;		
}					t_scene;

typedef struct s_line
{
	int		p1_x;
	int		p1_y;
	int		p2_x;
	int		p2_y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;
}			t_line;

typedef struct s_vector
{
	float			x;
	float			y;
	float			z;
	float			a;
	struct s_vector	*next;
}					t_vector;

void		ft_vctrclear(t_vector **pnt, void (*del)(void*));
void		ft_vctrdelone(t_vector *lst, void (*del)(void*));
int			ft_vctrsize(t_vector *pnt);
void		ft_vctrset(t_vector *vctr, float x, float y, float z);
t_vector	*ft_vctrnew(float x, float y, float z);
void		ft_vctradd_back(t_vector **vctr, t_vector *new);
t_vector	*ft_vctrlast(t_vector *pnt);
float		ft_vctrrng(t_vector *pnt);

t_vector	*vctr_generate(t_vector **map);
void		vctr_rotate(t_vector *vctr, t_vector *rotation);
void		vctr_translate(t_vector *vctr, float x, float y, float z);
void		scn_translate(t_scene *scene, t_vector *trnslt);
void		vctr_scale(t_vector *vctr, float zoom);
void		vctr_normalize(t_vector *vctr, t_vector *min, t_vector *max);
void		vctr_draw(t_data *img, t_vector *vctr);
void		vctr_get_border(t_vector *vctr, t_vector *min, t_vector *max);
void		vctr_get_center(t_vector *center, t_vector *min, t_vector *max);
void		vctr_print(t_vector *vctr);

t_vector	*create_points(char *file);
t_vector	*fdf_errors(int code);
void		generate_vectors(t_data *img, t_vector **map, int line);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *img, t_vector *p1, t_vector *p2, int color);

void		project(t_scene *scene);
t_vector	*parallel(t_vector *vctr);
t_vector	*isometric(t_vector *vctr);

float		degr_to_rad(int degrees);
float		bigger_abs(float a, float b);
int			elem_in_line(t_vector **map);

void		key_events(t_scene *scene);

void		scn_update_borders(t_scene *scene);
void		scn_normalize(t_scene *scene);
t_scene		*scn_init(t_vector *map);
void		scn_dstr(t_scene *scene);
t_data		*img_init(t_scene *scene);
void		scn_fit(t_scene *scene);

#endif
