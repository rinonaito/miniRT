/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:37:26 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 22:28:10 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>

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
}	t_ray;

// typedef struct s_ambient_lightning
// {
// 	double	lightning_ratio;
// 	t_rgb	color;
// }	t_ambient_lightning;

/**
 * origin 位置ベクトル
 * direction_vec 変移ベクトル
 * fov 視野角
*/
typedef struct s_camera
{
	t_vector3d	origin;
	t_vector3d	direction_vec;
	int			fov;
}	t_camera;

// typedef struct s_light
// {
// 	t_vector3d	origin;
// 	double			lightning_ratio;
// 	t_rgb			color;
// }	t_light;

typedef struct s_sphere
{
	t_vector3d	center;
	double		diameter;
	t_rgb		color;
}	t_sphere;

// typedef struct s_plane
// {
// 	t_vector3d	coordinate;
// 	t_vector3d	direction_vec;
// 	t_rgb			color;
// }	t_plane;

// typedef struct s_cylinder
// {
// 	t_vector3d	center;
// 	t_vector3d	direction_vec;
// 	double			diameter;
// 	double			height;
// 	t_rgb			color;
// } t_cylinder;

typedef struct s_scene
{
	// t_ambient_lightning	ambient;
	t_camera			camera;
	// t_light			*lights;
	t_sphere			*spheres;
	// t_plane 			*planes;
	// t_cylinder 		*cylinders;
	//size_t				lights_num;
	size_t				spheres_num;
	//size_t				planes_num;
	//size_t				cylinders_num;
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
