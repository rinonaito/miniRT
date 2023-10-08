/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:19:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/08 17:36:11 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"
#include "object.h"
#include <stdbool.h>
#include <math.h>

double	hit_circle(const t_ray ray, const void *object)
{
	t_circle	*circle;
	double		hit_distance;
	t_vector3d	point;
	t_vector3d	point_minus_center;
	t_plane		plane;

	circle = (t_circle *)object;
	plane.coordinate = circle->center;
	plane.direction_vec = circle->direction_vec;
	hit_distance = hit_plane(ray, (void *)&plane);
	if (hit_distance < 0)
		return (NOT_HIT);
	point = addition_vector3d(ray.origin,
			vector3d_dot_double(ray.direction_vec, hit_distance));
	point_minus_center
		= subtraction_vector3d(point, circle->center);
	if (dot_vector3d(point_minus_center, point_minus_center)
		<= pow(circle->diameter / 2, 2))
		return (hit_distance);
	return (NOT_HIT);
}
