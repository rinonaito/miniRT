/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_by_spot_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/15 17:56:44 by rnaito           ###   ########.fr       */
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
	t_ray spot_light_ray,
	const t_scene scene,
	t_vector3d original_point,
	const t_light light)
{
	double			distance_point_to_light;

	set_closest_point_info_in_ray(&spot_light_ray, scene);
	distance_point_to_light
		= get_len_of_vector3d(
			subtraction_vector3d(original_point, light.origin));
	if (_have_object_between_point_to_light(
			spot_light_ray.hit_distance, distance_point_to_light))
		return (false);
	else
		return (true);
}
