/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_hit_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/06 17:50:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "calculator.h"
#include <math.h>
#include <stdbool.h>

static	bool	_is_inside_of_upper_cone(
	const t_ray ray,
	const t_vector3d cone_top,
	const t_vector3d cone_dir,
	const double phi)
{
	double		angle_gap;

	(void)cone_top;
	angle_gap = acos(dot_vector3d(cone_dir, ray.direction_vec)) * 180.0 / M_PI;
	if (angle_gap < phi)
		return (true);
	return (false);
}

static bool	_is_out_of_height_range(
	const t_cone cone,
	const t_vector3d top_to_point)
{
	t_vector3d	projection_on_axis;
	double		len;

	projection_on_axis = get_projection_vector(
			cone.direction_vec, top_to_point);
	len = get_len_of_vector3d(projection_on_axis);
	if (len >= cone.height)
		return (true);
	return (false);
}

static bool	_hit_with_the_other_cone(
		t_vector3d top_to_point,
		t_vector3d cone_dir)
{
	return (dot_vector3d(normalize_vector3d(top_to_point), cone_dir) < 0);
}

/**
 * 円錐とレイとの交点が、有効であるかどうかの判定
 * 	⑴ 交点が円錐の高さの範囲外である場合
 *  ⑵ 交点が円錐の方向ベクトルと逆方向に存在する場合
*/
int	is_invalid_hit_point(
	const t_ray ray,
	const t_cone cone,
	const double hit_distance)
{
	t_vector3d	point;
	t_vector3d	top_to_point;

	point = addition_vector3d(ray.origin,
			vector3d_dot_double(ray.direction_vec, hit_distance));
	top_to_point = subtraction_vector3d(point, cone.top);
	if (!_hit_with_the_other_cone(top_to_point, cone.direction_vec)
		&& _is_out_of_height_range(cone, top_to_point))
		return (NO_VALID_POINT);
	if (_hit_with_the_other_cone(top_to_point, cone.direction_vec))
	{
		if (_is_inside_of_upper_cone(
				ray, cone.top, cone.direction_vec, cone.phi))
			return (GET_ANOTHER_HIT_POINT);
		else
			return (NO_VALID_POINT);
	}
	return (VALID_HIT_POINT);
}
