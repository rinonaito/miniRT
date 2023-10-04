/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:42:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/04 22:03:21 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "mlx_utils.h"
#include "color.h"
#include "vector.h"
#include "calculator.h"
#include "config.h"	
#include "light.h"
#include "init.h"
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
		current_hit_distance
			= scene.objects[i].fp_hit_object(ray, scene.objects[i].object);
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

	set_vector3d(&normal_vector, 0.0, 0.0, 0.0);
	_set_closest_point_info(
		&closest_hit_distance, &closest_object_i, *ray, scene);
	if (closest_object_i != NOT_HIT)
	{
		//
		if (scene.objects[closest_object_i].object_type == TUBE)
			return (convert_rgb_in_int(((t_tube *)scene.objects[closest_object_i].object)->color));
		if (scene.objects[closest_object_i].object_type == CIRCLE)
			return (convert_rgb_in_int(((t_circle *)scene.objects[closest_object_i].object)->color));
		normal_vector
			= scene.objects[closest_object_i].fp_get_normal_vector_for_object(
				*ray,
				closest_hit_distance,
				scene.objects[closest_object_i].object);
		set_lighting_ratio(ray, xyz, scene, normal_vector);
		return (scene.objects[closest_object_i].fp_get_pixel_color_for_object(
				scene.objects[closest_object_i].object,
				*ray,
				scene.ambient.lighting_ratio));
	}
	else
		return (0);
}
