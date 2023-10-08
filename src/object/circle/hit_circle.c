/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naitorino <naitorino@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:19:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 22:11:09 by naitorino        ###   ########.fr       */
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

	circle = (t_circle *)object;
	circle->direction_vec = normalize_vector3d(circle->direction_vec);
	hit_distance = hit_plane(ray, (void *)circle);
	point = addition_vector3d(ray.origin,
			vector3d_dot_double(ray.direction_vec, hit_distance));
	point_minus_center
		= subtraction_vector3d(point, circle->center);
	if (dot_vector3d(point_minus_center, point_minus_center)
		<= pow(circle->diameter / 2, 2))
		return (hit_distance);
	return (NOT_HIT);
}