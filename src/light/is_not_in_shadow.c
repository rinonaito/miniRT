/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_in_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:38:54 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 21:35:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h> 
#include "types.h"
#include "vector.h"
#include "config.h"
#include "src.h"
#include "init.h"

bool	is_not_in_shadow(
	const t_scene scene,
	const t_ray	ray,
	const t_vector3d point,
	const t_light light)
{
	t_ray	point_to_light;
	double	distance_point_to_light;

	(void)ray;
	set_ray(&point_to_light, point, light.origin);
	point_to_light.origin
		= addition_vector3d(point_to_light.origin ,vector3d_dot_double(point_to_light.direction_vec, 1.0/512.0));
	set_closest_point_info_in_ray(&point_to_light, scene);
	distance_point_to_light
		= get_len_of_vector3d(subtraction_vector3d(point, light.origin));
//	printf("ray[%lf, %lf, %lf]\n", point_to_light.direction_vec.x, point_to_light.direction_vec.y, point_to_light.direction_vec.z);
//	printf("light[%lf, %lf, %lf]\n", light.origin.x, light.origin.y, light.origin.z);
//	printf("point[%lf, %lf, %lf]\n", point.x, point.y, point.z);
	if (point_to_light.hit_distance < distance_point_to_light && point_to_light.hit_distance != DBL_MAX)
	{
//		printf("hit_dustance = %lf distance = %lf\n", point_to_light.hit_distance, distance_point_to_light);
		return (false);
	}
//	printf("is NOT in shadow!\n");
	return (true);
}
