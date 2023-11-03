/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:19:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/08 19:08:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "object.h"
#include <stdbool.h>
#include <math.h>

static double	_hit_plane_containing_the_circle(
	const t_ray ray,
	const t_circle *circle)
{
	t_plane		plane;

	plane.coordinate = circle->center;
	plane.direction_vec = circle->direction_vec;
	return (hit_plane(ray, (void *)&plane));
}

static bool	_point_is_within_radius(
	const t_vector3d point_minus_center,
	double radius)
{
	return (dot_vector3d(point_minus_center, point_minus_center)
		<= pow(radius, 2.0));
}

double	hit_circle(const t_ray ray, const void *object)
{
	t_circle	*circle;
	double		hit_distance;
	t_vector3d	point;
	t_vector3d	point_minus_center;

	circle = (t_circle *)object;
	hit_distance = _hit_plane_containing_the_circle(ray, circle);
	if (hit_distance < 0.0)
		return (NOT_HIT);
	point = addition_vector3d(ray.origin,
			vector3d_dot_double(ray.direction_vec, hit_distance));
	point_minus_center
		= subtraction_vector3d(point, circle->center);
	if (_point_is_within_radius(
			point_minus_center, circle->diameter / 2.0))
		return (hit_distance);
	return (NOT_HIT);
}
