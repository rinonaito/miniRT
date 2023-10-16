/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:42:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/16 20:18:08 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "calculator.h"
#include "config.h"
#include "types.h"
#include <math.h>
#include <stdlib.h>

static double	_get_closer_hit_distance_for_sphere(
	const t_ray ray,
	const t_vector3d center,
	const double radius)
{
	double		a;
	double		b;
	double		c;
	double		hit_distance;
	t_vector3d	ray_origin_minus_center;

	ray_origin_minus_center = subtraction_vector3d(center, ray.origin);
	a = dot_vector3d(ray.direction_vec, ray.direction_vec);
	b = -2.0 * dot_vector3d(ray.direction_vec, ray_origin_minus_center);
	c = dot_vector3d(ray_origin_minus_center, ray_origin_minus_center)
		- pow(radius, 2.0);
	hit_distance = get_closer_hit_distance(a, b, c);
	if (hit_distance < 0.0)
		return (NOT_HIT);
	return (hit_distance);
}

/**
 * レイが球と接する点の数を取得する関数
 * ＜前提＞
 * - レイ上の点(point)、球の中心(center)、球の半径(radius)の関係は
 *   次の式で表現できる：(point - center)^2 = radius^2
 * - pointは、次の式で表現できる：point = origin + t * direction

 * 上記をもとに、tに関する二次方程式 at^2 + bt + c = 0を作成し、
 * 球とレイの接点の数(0 ~ 2)を求め、返す
*/
double	hit_sphere(const t_ray ray, const void *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	return (_get_closer_hit_distance_for_sphere(
			ray, sphere->center, sphere->diameter / 2.0));
}
