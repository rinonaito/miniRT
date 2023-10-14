/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_by_spot_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/14 17:53:33 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h> 
#include "types.h"
#include "vector.h"
#include "config.h"
#include "src.h"
#include "init.h"

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
//	printf("\n\n<SHADOW RAY>\n");
	// printf("Shadow ray: Origin (%lf, %lf, %lf), Direction (%lf, %lf, %lf)\n\n",
	// 	spot_light_ray.origin.x, spot_light_ray.origin.y, spot_light_ray.origin.z,
	// 	spot_light_ray.direction_vec.x, spot_light_ray.direction_vec.y, spot_light_ray.direction_vec.z);
	set_closest_point_info_in_ray(&spot_light_ray, scene);
	if (spot_light_ray.hit_distance != DBL_MAX)
		printf("hit with algun object\n");
	distance_point_to_light
		= get_len_of_vector3d(subtraction_vector3d(point, light.origin));
//	printf("<JUDGING FUNCTION>\n");
//	printf("spot_light_ray.hitdistance = %lf\n", spot_light_ray.hit_distance);
//	printf("distance_point_to_light= %lf\n\n", distance_point_to_light);
	if (spot_light_ray.hit_distance == DBL_MAX)
		return (true);
	else if (spot_light_ray.hit_distance < distance_point_to_light)
		return (false);
	return (true);
}
