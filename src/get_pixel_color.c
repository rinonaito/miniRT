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
#include "light.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * レイ(視線)がシーン内のオブジェクトに当たる最も近い点を探す
 */
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
	t_vector3d	normal_vector;
	ssize_t		closest_object_i;
	double		closest_hit_distance;

	_set_closest_point_info(
		&closest_hit_distance, &closest_object_i, *ray, scene);
	if (closest_object_i != NOT_HIT)
	{
		normal_vector = get_normal_vector_for_sphere(*ray, closest_hit_distance,
				((t_sphere *)scene.objects[closest_object_i].object)->center);
		set_lighting_ratio(ray, xyz, scene, normal_vector);
		return (convert_rgb_in_int(reflect_lighting_ratio_in_color(
					((t_sphere *)scene.objects[closest_object_i].object)->color,
					ray->rgb,
					scene.ambient.lighting_ratio, ray->lighting_ratio)));
	}
	else
	{
		return (0);
	}
}
