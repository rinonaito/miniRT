/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:42:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 13:58:53 by yshimoma         ###   ########.fr       */
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

static double	_calculate_lighting(
	const t_vector3d point,
	const double lighting_ratio,
	const t_vector3d normal_vector)
{
	double		cos_theta;
	double		dot_result;
	double		dot_length;

	dot_result = dot_vector3d(point, normal_vector);
	dot_length = vector3d_magnitude(point)
		* vector3d_magnitude(normal_vector);
	cos_theta = dot_result / dot_length;
	if (cos_theta > NO_LIGHT_STRENGTH)
		return (lighting_ratio * cos_theta);
	else
		return (NO_LIGHT_STRENGTH);
}

static void	_set_lighting_ratio(
	t_ray *ray,
	const t_vector3d point,
	const t_scene scene,
	const t_vector3d normal_vector)
{
	size_t	i;

	ray->lighting_ratio += _calculate_lighting(
			subtraction_vector3d(point, ray->origin),
			scene.ambient.lighting_ratio,
			normal_vector);
	i = 0;
	while (i < scene.lights_num)
	{
		ray->lighting_ratio += _calculate_lighting(
				subtraction_vector3d(point, scene.lights[i].origin),
				scene.lights[i].lighting_ratio,
				normal_vector);
		i++;
	}
}

int	get_color_in_image(
	t_ray *ray,
	const t_vector3d xyz,
	const t_scene scene)
{
	double		hit_distance;
	t_rgb		rgb;
	t_rgb		else_rgb;
	t_vector3d	normal_vector;

	hit_distance = hit_sphere(*ray, scene.spheres[0].center,
			scene.spheres[0].diameter / 2);
	if (hit_distance >= HIT_DISTANCE_MIN)
	{
		normal_vector = get_normal_vector_for_sphere(*ray, hit_distance,
				scene.spheres[0].center);
		_set_lighting_ratio(ray, xyz, scene, normal_vector);
		rgb = get_pixel_color(
				scene.spheres[0].color, ray->lighting_ratio);
		return (convert_rgb_in_int(rgb));
	}
	else
	{
		_set_lighting_ratio(ray, xyz, scene, ray->direction_vec);
		else_rgb.red = 0;
		else_rgb.green = 0;
		else_rgb.blue = 255;
		return (
			convert_rgb_in_int(get_pixel_color(else_rgb, ray->lighting_ratio)));
	}
}
