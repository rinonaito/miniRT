/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:37:26 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/23 20:08:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	z;
}	t_coordinate;

//移動するかも
typedef struct s_ray
{
	t_coordinate	origin;
	t_coordinate	direction_vec;
}	t_ray;

// typedef struct s_ambient_lightning
// {
// 	double	lightning_ratio;
// 	t_rgb	color;
// }	t_ambient_lightning;

typedef struct s_camera
{
	t_coordinate	origin;
	t_coordinate	direction_vec;
	int				fov;
}	t_camera;

// typedef struct s_light
// {
// 	t_coordinate	origin;
// 	double			lightning_ratio;
// 	t_rgb			color;
// }	t_light;

typedef struct s_sphere
{
	t_coordinate	center;
	double			diameter;
	t_rgb			color;
}	t_sphere;

// typedef struct s_plane
// {
// 	t_coordinate	coordinate;
// 	t_coordinate	direction_vec;
// 	t_rgb			color;
// }	t_plane;

// typedef struct s_cylinder
// {
// 	t_coordinate	center;
// 	t_coordinate	direction_vec;
// 	double			diameter;
// 	double			height;
// 	t_rgb			color;
// } t_cylinder;

typedef struct s_scene
{
	// t_ambient_lightning	ambient;
	t_camera			camera;
	// t_light				*lights;
	t_sphere			*spheres;
	// t_plane 			*planes;
	// t_cylinder 			*cylinders;
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
