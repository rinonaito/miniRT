/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/16 19:20:56 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "calculator.h"
#include <math.h>
#include <stdbool.h>

// static double	_get_a(
// 	t_ray ray,
// 	t_vector3d cone_direction,
// 	double cone_phi)
// {
// 	double x;
// 	double y;
// 	double z;

// 	x = cos(cone_phi) * cos(cone_phi);
// 	y = dot_vector3d(ray.direction_vec, ray.direction_vec);
// 	z = pow(dot_vector3d(ray.direction_vec, cone_direction), 2);
// 	return (x * y - z); 
// }

// static double	_get_b(
// 	t_ray ray,
// 	t_vector3d cone_direction,
// 	double cone_phi,
// 	t_vector3d cone_top)
// {
// 	double	x;
// 	double	y;
// 	double	z;

// 	x = cos(cone_phi) * cos(cone_phi);
// 	y = dot_vector3d(cone_direction, cone_direction);
// 	z = dot_vector3d(ray.direction_vec,
// 			subtraction_vector3d(ray.origin, cone_top));
// 	return (2 * (x * z - y * z));
// }

// static double	_get_c(
// 	t_ray ray,
// 	t_vector3d cone_direction,
// 	double cone_phi,
// 	t_vector3d cone_top)
// {
// 	double		x;
// 	double		y;
// 	double		z;
// 	t_vector3d	ray_minus_top;

// 	ray_minus_top = subtraction_vector3d(ray.origin, cone_top);
// 	x = cos(cone_phi) * cos(cone_phi);
// 	y = dot_vector3d(ray_minus_top, ray_minus_top);
// 	z = pow((dot_vector3d(ray_minus_top, cone_direction)), 2);
// 	return (x * y - z);
// }

// static bool	_is_out_of_height_range(
// 	const t_ray ray,
// 	const t_tube tube,
// 	const double hit_distance)
// {
// 	t_vector3d	point;
// 	double		a;

// 	point = addition_vector3d(ray.origin,
// 			vector3d_dot_double(ray.direction_vec, hit_distance));
// 	a = dot_vector3d(subtraction_vector3d(point, tube.center),
// 			tube.direction_vec);
// 	if (pow(a, 2.0) >= pow(tube.height / 2.0, 2.0))
// 		return (true);
// 	else
// 		return (false);
// }

// double	hit_cone(const t_ray ray, const void *object)
// {
// 	t_cone		*cone;
// 	double		a;
// 	double		b;
// 	double		c;
// 	double		hit_distance;

// 	cone = (t_cone *)object;
// 	a = _get_a(ray, cone->direction_vec, cone->phi);
// 	b = _get_b(ray, cone->direction_vec, cone->phi, cone->top);
// 	c = _get_c(ray, cone->direction_vec, cone->phi, cone->top);
// 	hit_distance = get_closer_hit_distance(a, b, c);
// //	if (_is_out_of_height_range(ray, *cone, hit_distance))
// //		hit_distance = NOT_HIT;
// 	if (hit_distance <= NOT_HIT)
// 		return (NOT_HIT);
// 	printf("hit_with_cylinder\n");
// 	return (hit_distance);
// }

double	hit_cone(const t_ray ray, const void *object)
{
	t_cone		*cone;
	double		a;
	double		b;
	double		c;
	double		hit_distance;

	cone = (t_cone *)object;
	t_vector3d	tb
		= vector3d_dot_double(ray.direction_vec, cos(cone->phi));
	t_vector3d	tq
		= vector3d_dot_double(
			subtraction_vector3d(ray.origin, cone->top), cos(cone->phi));
	t_vector3d	r
		= dot_vector3d(subtraction_vector3d(ray.origin, cone->top))


	hit_distance = get_closer_hit_distance(a, b, c);
	if (hit_distance <= NOT_HIT)
		return (NOT_HIT);
	printf("hit_with_cylinder\n");
	return (hit_distance);
}
