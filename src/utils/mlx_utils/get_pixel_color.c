/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:42:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 14:23:10 by yshimoma         ###   ########.fr       */
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
	const t_vector3d ray,
	const t_vector3d normal_vector,
	const double lighting_ratio)
{
	double		cos_theta;
	double		dot_result;
	double		dot_length;

	dot_result = dot_vector3d(ray, normal_vector);
	dot_length = get_len_of_vector3d(ray)
		* get_len_of_vector3d(normal_vector);
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

	ray->lighting_ratio += scene.ambient.lighting_ratio;
	i = 0;
	while (i < scene.lights_num)
	{
		ray->lighting_ratio += _calculate_lighting(
				normalize_vector3d(subtraction_vector3d(point,
						scene.lights[i].origin)),
				normal_vector,
				scene.lights[i].lighting_ratio);
		i++;
	}
}

static void	_set_closest_point_info(
	double *closest_hit_distance,
	ssize_t *closest_object_index,
	const t_ray ray,
	const t_scene scene)
{
	size_t	i;
	double	current_hit_distance;

	i = 0;
	*closest_hit_distance = INFINITY;
	*closest_object_index = NOT_HIT;
	while (i < scene.objects_num)
	{
		if (scene.objects[i].object_type == SPHERE)
		{
			current_hit_distance
				= hit_sphere(
					ray,
					((t_sphere *)scene.objects[i].object)->center,
					((t_sphere *)scene.objects[i].object)->diameter
					/ HALF_FACTOR);
		}
		if (current_hit_distance >= HIT_DISTANCE_MIN
			&& current_hit_distance < *closest_hit_distance)
		{
			*closest_hit_distance = current_hit_distance;
			*closest_object_index = i;
		}
		i++;
	}
}

int	get_pixel_color(
	t_ray *ray,
	const t_vector3d xyz,
	const t_scene scene)
{
	t_rgb		else_rgb;
	t_vector3d	normal_vector;
	ssize_t		closest_object_i;
	double		closest_hit_distance;

	_set_closest_point_info(
		&closest_hit_distance, &closest_object_i, *ray, scene);
	if (closest_object_i != NOT_HIT)
	{
		normal_vector = get_normal_vector_for_sphere(*ray, closest_hit_distance,
				((t_sphere *)scene.objects[closest_object_i].object)->center);
		_set_lighting_ratio(ray, xyz, scene, normal_vector);
		return (convert_rgb_in_int(reflect_lighting_ratio_in_color(
					((t_sphere *)scene.objects[closest_object_i].object)->color,
					ray->lighting_ratio)));
	}
	else
	{
		_set_lighting_ratio(ray, xyz, scene, ray->direction_vec);
		else_rgb.red = 0;
		else_rgb.green = 0;
		else_rgb.blue = 0;
		return (convert_rgb_in_int(reflect_lighting_ratio_in_color(
					else_rgb, ray->lighting_ratio)));
	}
}
