/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:08:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:14:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include <math.h>

/**
 * レイが平面と接する点を取得する関数
 * ＜前提＞
 * - 平面の方程式は次のように表現される：(point - coordinate)・direction_vec = 0
 *   ここで、pointは平面上の任意の点、coordinateは平面上の特定の点、
 *   direction_vecは平面の法線ベクトル
 * - レイの方程式は次のように表現される：point = origin + t * direction_vec
 * 
 * 上記をもとに、レイが平面と接する点を計算するためのtの値を求め、返す。
 * tの値が0以上の場合、それはレイの出発点からの距離を示している。
 * レイが平面と交差しない場合は、INFINITYを返す。
 */
double	hit_plane(const t_ray ray, const void *object)
{
	t_plane		*plane;
	double		denom;
	double		t;
	t_vector3d	oc;

	plane = (t_plane *)object;
	denom = dot_vector3d(ray.direction_vec, plane->direction_vec);
	if (fabs(denom) > 0.0)
	{
		oc = subtraction_vector3d(ray.origin, plane->coordinate);
		t = dot_vector3d(oc, plane->direction_vec) / denom;
		if (t >= 0)
			return (t);
	}
	return (INFINITY);
}
