/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 15:18:40 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "calculator.h"
#include <math.h>
#include <stdbool.h>

/**
 * 円錐とレイとの衝突判定に使用する二次方程式（ax^2 + bx + c = 0）の
 * 係数(a, b, c)を取得し、引数coefficientへ格納する。
 * coefficient[0] = a, coefficient[1] = b, coefficient[2] = c 
*/
static void	_set_coeffients(double *coefficients, t_ray ray, t_cone cone)
{
	double		phi_in_radian;
	t_vector3d	a;
	t_vector3d	b;
	double		c;
	double		d;

	phi_in_radian = cone.phi * M_PI / HALF_FULL_DEGREE;
	a = vector3d_dot_double(ray.direction_vec, cos(phi_in_radian));
	b = vector3d_dot_double(
			subtraction_vector3d(ray.origin, cone.top), cos(phi_in_radian));
	c = dot_vector3d(ray.direction_vec, cone.direction_vec);
	d = dot_vector3d(
			cone.direction_vec, subtraction_vector3d(ray.origin, cone.top));
	coefficients[0] = dot_vector3d(a, a) - pow(c, 2.0);
	coefficients[1] = 2 * (dot_vector3d(a, b) - c * d);
	coefficients[2] = dot_vector3d(b, b) - pow(d, 2.0);
}

/**
 * 円錐とレイとの交点が、円錐頂点から与えられた高さの範囲外であることを判定する
 * ⑴ 交点が円錐頂点より上方向にある
 * ⑵ 交点が円錐の高さの範囲外である
*/
static bool	_is_out_of_height_range(
	const t_ray ray,
	const t_cone cone,
	const double hit_distance)
{
	t_vector3d	point;
	double		a;

	point = addition_vector3d(ray.origin,
			vector3d_dot_double(ray.direction_vec, hit_distance));
	a = dot_vector3d(subtraction_vector3d(point, cone.top),
			cone.direction_vec);
	if (a < 0)
		return (true);
	if (pow(a, 2.0) >= pow(cone.height, 2.0))
		return (true);
	return (false);
}

double	hit_cone(const t_ray ray, const void *object)
{
	t_cone		*cone;
	double		coefficients[3];
	double		hit_distance;

	cone = (t_cone *)object;
	_set_coeffients(coefficients, ray, *cone);
	hit_distance = get_closer_hit_distance(
			coefficients[0], coefficients[1], coefficients[2]);
	if (hit_distance <= NOT_HIT)
		return (NOT_HIT);
	if (_is_out_of_height_range(ray, *cone, hit_distance))
		hit_distance = NOT_HIT;
	return (hit_distance);
}
