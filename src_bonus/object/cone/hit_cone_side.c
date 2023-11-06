/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/06 17:51:30 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "calculator.h"
#include "object.h"
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

double	hit_cone_side(
	const t_ray ray,
	const void *object)
{
	t_cone		*cone;
	double		coefficients[3];
	double		hit_distance;
	int			ret;

	cone = (t_cone *)object;
	_set_coeffients(coefficients, ray, *cone);
	hit_distance = get_closer_hit_distance(
			coefficients[0], coefficients[1], coefficients[2]);
	if (hit_distance <= 0)
		return (NOT_HIT);
	ret = is_invalid_hit_point(ray, *cone, hit_distance);
	if (ret == NO_VALID_POINT)
		return (NOT_HIT);
	else if (ret == GET_ANOTHER_HIT_POINT)
	{
		hit_distance = get_farer_hit_distance(
				coefficients[0], coefficients[1], coefficients[2]);
		if (hit_distance <= 0
			|| is_invalid_hit_point(ray, *cone, hit_distance)
			== NO_VALID_POINT)
			return (NOT_HIT);
	}
	return (hit_distance);
}
