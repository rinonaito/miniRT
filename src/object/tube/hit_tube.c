/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naitorino <naitorino@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:18:56 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 21:09:36 by naitorino        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "calculator.h"
#include <math.h>
#include <stdbool.h>

static double	_get_a(
		t_vector3d ray_dir,
		t_vector3d cylinder_dir)
{
	return (dot_vector3d(ray_dir, ray_dir)
		* dot_vector3d(cylinder_dir, cylinder_dir)
		- pow(dot_vector3d(ray_dir, cylinder_dir), 2));
}

static double	_get_b(
		t_vector3d point_minus_center,
		t_vector3d ray_dir,
		t_vector3d cylinder_dir)
{
	return (2 * dot_vector3d(point_minus_center, ray_dir)
		* dot_vector3d(cylinder_dir, cylinder_dir)
		- dot_vector3d(point_minus_center, cylinder_dir)
		* dot_vector3d(ray_dir, cylinder_dir));
}

static double	_get_c(
		t_vector3d point_minus_center,
		t_vector3d cylinder_dir,
		double cylinder_radius)
{
	return (dot_vector3d(point_minus_center, point_minus_center)
		* dot_vector3d(cylinder_dir, cylinder_dir)
		- pow(dot_vector3d(point_minus_center, cylinder_dir), 2)
		- pow(cylinder_radius, 2));
}

static bool	_is_out_of_height_range(
	t_ray ray,
	t_tube tube,
	double hit_distance)
{
	t_vector3d	point;
	double		a;

	point = addition_vector3d(ray.origin,
			vector3d_dot_double(ray.direction_vec, hit_distance));
	a = dot_vector3d(subtraction_vector3d(point, tube.center),
			tube.direction_vec);
	if (pow(a, 2) >= pow(tube.height, 2) / 4)
		return (true);
	else
		return (false);
}

double	hit_tube(const t_ray ray, const void *object)
{
	t_tube		*tube;
	double		a;
	double		b;
	double		c;
	double		hit_distance;

	tube = (t_tube *)object;
	tube->direction_vec = normalize_vector3d(tube->direction_vec);
	a = _get_a(ray.direction_vec, tube->direction_vec);
	b = _get_b(subtraction_vector3d(ray.origin, tube->center),
			ray.direction_vec, tube->direction_vec);
	c = _get_c(subtraction_vector3d(ray.origin, tube->center),
			tube->direction_vec,
			tube->diameter / 2);
	hit_distance = get_hit_distance(a, b, c);
	if (_is_out_of_height_range(ray, *tube, hit_distance))
		hit_distance = NOT_HIT;
	return (hit_distance);
}
