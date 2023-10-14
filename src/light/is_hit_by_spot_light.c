/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_by_spot_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/14 18:24:28 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h> 
#include "types.h"
#include "vector.h"
#include "config.h"
#include "src.h"
#include "init.h"

bool	_have_object_between_point_to_light(
	const double hit_distance,
	const double distance_point_to_light)
{
	if (hit_distance == DBL_MAX)
		return (false);
	else if (hit_distance < distance_point_to_light)
		return (true);
	else
		return (false);
}

bool	is_hit_by_spot_light(
	const t_scene scene,
	const t_vector3d point,
	const t_light light)
{
	t_ray	spot_light_ray;
	double	distance_point_to_light;

	set_ray(&spot_light_ray, point, light.origin);
//	spot_light_ray.origin
//		= addition_vector3d(spot_light_ray.origin,
//			vector3d_dot_double(spot_light_ray.direction_vec, 1.0 / 512.0));
	set_closest_point_info_in_ray(&spot_light_ray, scene);
	distance_point_to_light
		= get_len_of_vector3d(subtraction_vector3d(point, light.origin));
	if (_have_object_between_point_to_light(
			spot_light_ray.hit_distance, distance_point_to_light))
		return (false);
	else
		return (true);
}
