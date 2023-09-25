/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:42:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/25 21:36:04 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "calculator.h"

/**
 * レイが球と接する点の数を取得する関数
 * ＜前提＞
 * - 球の表面上の点(point)、球の中心(center)、球の半径(radius)の関係は
 *   次の式で表現できる：(point - center)^2 = radius^2
 * - pointは、次の式で表現できる：point = origin + t * direction

 * 上記をもとに、tに関する二次方程式 at^2 + bt + c = 0を作成し、
 * 球とレイの接点の数(0 ~ 2)を求め、返す
*/
size_t	hit_sphere(t_ray ray, t_vector3d center, double radius)
{		
	t_vector3d	point_minus_center;
	double		a;
	double		b;
	double		c;

	point_minus_center = subtraction_vector3d(ray.origin, center);
	a = dot_vector3d(ray.direction_vec, ray.direction_vec);
	b = 2 * dot_vector3d(ray.direction_vec, point_minus_center);
	c = dot_vector3d(point_minus_center, point_minus_center) - pow(radius, 2);
	return (get_num_of_positive_solutions(a, b, c));
}
