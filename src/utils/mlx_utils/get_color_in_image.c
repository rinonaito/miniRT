/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:42:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 11:42:39 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "sphere.h"
#include "mlx_utils.h"
#include "color.h"
#include "vector.h"
#include "calculator.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double	_get_lighting_ratio(
	t_ray *ray,
	t_vector3d point,
	t_scene scene,
	t_vector3d normal_vector)
{
	double		cos_theta;
	double		dot_result;
	double		dot_length;
	t_vector3d	point_to_camera;

	point_to_camera = subtraction_vector3d(point, ray->origin);
	dot_result = dot_vector3d(point_to_camera, normal_vector);
	dot_length = vector3d_magnitude(point_to_camera)
		* vector3d_magnitude(normal_vector);
	cos_theta = dot_result / dot_length;
	if (cos_theta < 0.0)
		return (0.0);
	return (scene.ambient.lighting_ratio * cos_theta);
}

int	get_color_in_image(
	t_ray *ray,
	const t_vector3d xyz,
	const t_scene scene)
{
	double		hit_distance;
	t_rgb		rgb;
	t_vector3d	normal_vector;

	hit_distance = hit_sphere(*ray, scene.spheres[0].center,
			scene.spheres[0].diameter / 2);
	if (hit_distance >= 0.0)
	{
		normal_vector = get_normal_vector_for_sphere(*ray, hit_distance,
				scene.spheres[0].center);
		ray->lighting_ratio
			= _get_lighting_ratio(ray, xyz, scene, normal_vector);
		rgb = get_pixel_color(
				scene.spheres[0].color, normal_vector, ray->lighting_ratio);
		return (convert_rgb_in_int(rgb));
	}
	else
	{
		ray->lighting_ratio
			= _get_lighting_ratio(ray, xyz, scene, ray->direction_vec);
		return (0x0000FF * ray->lighting_ratio);
	}
}
