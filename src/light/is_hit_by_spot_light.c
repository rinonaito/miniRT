/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_by_spot_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/14 19:29:12 by rnaito           ###   ########.fr       */
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
	t_vector3d point,
	const t_light light)
{
	const double	thickness = 1.0 / 512.0;
	t_ray			spot_light_ray;
	t_vector3d		spot_light_ray_direction;
	double			distance_point_to_light;

	spot_light_ray_direction = normalize_vector3d(
			subtraction_vector3d(light.origin, point));
	point = addition_vector3d(point,
			vector3d_dot_double(spot_light_ray_direction, thickness));
	set_ray(&spot_light_ray, point, light.origin, scene.ambient);
	set_closest_point_info_in_ray(&spot_light_ray, scene);
	distance_point_to_light
		= get_len_of_vector3d(subtraction_vector3d(point, light.origin));
	if (_have_object_between_point_to_light(
			spot_light_ray.hit_distance, distance_point_to_light))
		return (false);
	else
		return (true);
}
