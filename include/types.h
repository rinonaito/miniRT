/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:37:26 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/12 22:46:42 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>
# include <stdio.h>

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	TUBE,
	CIRCLE,
}	t_object_type;

typedef enum e_view_port
{
	CENTER = 0,
	RIGHT = 1,
	DOWN = 2,
}	t_view_port;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

typedef struct s_vector2d
{
	double	x;
	double	y;
}	t_vector2d;

//移動するかも
typedef struct s_ray
{
	t_vector3d	origin;
	t_vector3d	direction_vec;
	double		lighting_ratio;
	double		hit_distance;
	ssize_t		hit_object_index;
	t_rgb		rgb;
}	t_ray;

typedef struct s_ambient_lighting
{
	double	lighting_ratio;
	t_rgb	color;
}	t_ambient_lighting;

/**
 * origin 位置ベクトル
 * direction_vec 変移ベクトル
 * fov 視野角
*/
typedef struct s_camera
{
	t_vector3d	origin;
	t_vector3d	direction_vec;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector3d	origin;
	double		lighting_ratio;
	t_rgb		color;
}	t_light;

typedef struct s_object
{
	void		*object;
	int			object_type;
	double		(*fp_hit_object)(
			const t_ray,
			const void *);
	t_vector3d	(*fp_get_normal_vector_for_object)(
		const t_ray,
		const void *);
	int			(*fp_get_pixel_color_for_object)(
			const void *,
			const t_ray ray,
			const double ambient_lighting_ratio);
}	t_object;

typedef struct s_sphere
{
	t_vector3d	center;
	double		diameter;
	t_rgb		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector3d	coordinate;
	t_vector3d	direction_vec;
	t_rgb		color;
}	t_plane;

typedef struct s_tube
{
	t_vector3d	center;
	t_vector3d	direction_vec;
	double		diameter;
	double		height;
	t_rgb		color;
}	t_tube;

typedef struct s_circle
{
	t_vector3d	center;
	t_vector3d	direction_vec;
	double		diameter;
	t_rgb		color;
}	t_circle;

typedef struct s_scene
{
	t_ambient_lighting	ambient;
	t_camera			camera;
	t_light				*lights;
	t_object			*objects;
	size_t				objects_num;
	size_t				lights_num;
}	t_scene;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

#endif
