/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gro-donn <gro-donn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:58:11 by gro-donn          #+#    #+#             */
/*   Updated: 2025/02/01 11:13:31 by gro-donn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h> //minilbx fns
# include <stdlib.h>
# define STDERR 2

typedef struct s_data_pix
{
	char			*addr;
	int				line_length;
	int				bits_per_pixel;
}					t_data_pix;

typedef struct s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				color;
}					t_line;

typedef struct s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bresenham;

typedef struct s_map_point
{
	float			z;
	int				color;
}					t_map_point;

typedef struct s_map
{
	int				cols;
	int				rows;
	//	Array of map points
	t_map_point		*values_z_color;

	float			z_min;
	float			z_max;
}					t_map;

typedef struct s_point3d
{
	float			x;
	float			y;
	float			z;
}					t_point3d;
typedef struct s_mlx_context
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx_context;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_point2d
{
	int				x;
	int				y;
}					t_point2d;

typedef struct s_app
{
	t_mlx_context	ctx;
	t_data			img;
	t_map			map;
	t_point2d		window_size;
	long			*map_array;
	t_point2d		*iso_points;
}					t_app;

typedef struct s_edge
{
	int				start;
	int				end;
}					t_edge;

int					handle_keypress(int keycode, void *param);
int					handle_exit(void *param);

int					count_words(const char *line);
char				*read_file_to_buffer(const char *filename);
void				handle_error(const char *message);
void				determine_dimensions(const char *buffer, t_map *map);

const char			*skip_whitespace(const char *buffer);
int					my_isdigit(char c);
size_t				ft_strlen(const char *str);
const char			*parse_number(const char *buffer, float *value);
const char			*parse_hex_color(const char *str, int *color);
int					get_digit_value(char c, int base);
int					is_digit_or_hex(char c, int base);
float				my_strtof(const char *str, char **endptr);

t_map_point			*read_z_color(int num_elems, char *buffer,
						int default_colour);
t_edge				*populate_edges(t_map *map, int edges_count);
void				find_min_max(t_map *map);

t_point2d			*prepare_iso_points(const t_map *map,
						t_point2d window_size);
void				to_pixel_coords(const t_map *map, const t_point3d *points,
						t_point2d *iso_points, t_point2d window_size);

void				draw_line(t_data *t_data_pix, t_point2d start,
						t_point2d end, int color);

#endif