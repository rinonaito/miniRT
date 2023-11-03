/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:42:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/02 20:34:09 by rnaito           ###   ########.fr       */
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
#include "src.h"
#include "object.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

t_vector3d	get_normal_vector_for_plane2(
	const t_ray ray,
	const t_vector3d point,
	const void *object,
	const t_bumpmap bumpmap);

int	get_pixel_color(
	t_ray *ray,
	const t_scene scene)
{
	t_vector3d	normal_vector;
	t_vector3d	point_on_object;	

	set_closest_point_info_in_ray(ray, scene);
	if (ray->hit_object_index != NOT_HIT)
	{
		point_on_object = addition_vector3d(ray->origin,
				vector3d_dot_double(ray->direction_vec, ray->hit_distance));
		normal_vector
			= get_normal_vector_for_plane2(
				*ray,
				point_on_object,
				scene.objects[ray->hit_object_index].object,
				scene.bump_map);
		// normal_vector
		// 	= scene.objects[ray->hit_object_index]
		// 	.fp_get_normal_vector_for_object(*ray,
		// 		point_on_object,
		// 		scene.objects[ray->hit_object_index].object);
		set_lighting_ratio(ray, point_on_object, scene, normal_vector);
		return (scene.objects[ray->hit_object_index]
			.fp_get_pixel_color_for_object(
				scene.objects[ray->hit_object_index].object,
				*ray,
				point_on_object));
	}
	else
		return (BLACK);
}
