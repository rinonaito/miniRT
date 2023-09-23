/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:37:26 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/23 18:00:15 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_rgb
{
	int red;
	int green;
	int blue;
} t_rgb;

typedef struct s_coordinate
{
	double	 x;
	double	 y;
	double	 z;
} t_coordinate;

//typedef struct s_map
//{
//	t_ambient_lightning	ambient;
//	t_camera			camera;
//	t_light				*lights;
//	t_sphere			*spheres;
//	t_plane 			*planes;
//	t_cylider 			*cylinders;
//}	t_map;
//
//typedef struct s_ambient_lightning
//{
//	double	lightning_ratio;
//	t_rgb 	color;
//}	t_ambient_lightning;
//
//typedef struct s_camera
//{
//	t_coordinate	coordinate;
//	t_coordinate	direction_vec;
//	int				fov;
//}	t_camera;
//
//typedef struct s_light
//{
//	t_coordinate	coordinate;
//	double			lightning_ratio;
//	t_rgb			color;
//}	t_light;
//
typedef struct s_sphere
{
	t_coordinate	coordinate;
	double				diameter;
	t_rgb				color;
}	t_sphere;

//typedef struct s_plane
//{
//	t_coordinate	coordinate;
//	t_coordinate	direction_vec;
//	t_rgb			color;
//}	t_plane;
//
//typedef struct s_cylinder
//{
//	t_coordinate	coordinate;
//	t_coordinate	direction_vec;
//	double			diameter;
//	double			height;
//	t_rgb			color;
//} t_cylinder;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
} t_mlx_data;

#endif
