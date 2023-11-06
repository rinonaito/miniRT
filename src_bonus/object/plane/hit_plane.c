/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:08:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/06 17:58:53 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include <math.h>

/**
 * レイが平面と接する点を取得する関数
 * ＜前提＞
 * - 平面の方程式は次のように表現される：(point - coordinate)・direction_vec = 0
 *   ここで、pointは平面上の任意の点、coordinateは平面上の特定の点、
 *   direction_vecは平面の法線ベクトル
 * - レイの方程式は次のように表現される：point = origin + hit_distance * direction_vec
 * 
 * 上記をもとに、レイが平面と接する点までの距離（hit_distance）を求め、返す。
 * hit_distanceが0の場合は、視線の方向ベクトルと平面が平行で、視界に映らないためNOT_HITを返す。
 */
double	hit_plane(
	const t_ray ray,
	const void *object)
{
	t_plane		*plane;
	double		hit_distance;

	plane = (t_plane *)object;
	hit_distance = dot_vector3d(
			subtraction_vector3d(plane->coordinate, ray.origin),
			plane->direction_vec)
		/ dot_vector3d(ray.direction_vec, plane->direction_vec);
	if (hit_distance < 0.0)
		return (NOT_HIT);
	return (hit_distance);
}
