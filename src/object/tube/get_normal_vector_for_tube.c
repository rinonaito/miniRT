/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_tube.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:17 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 15:11:11 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

t_vector3d	get_normal_vector_for_tube(
	const t_ray ray,
	const double hit_distance,
	const void *object)
{
	t_tube	*tube;
	t_vector3d	t_direction;
	t_vector3d	point;
	t_vector3d	normal_vector;
	t_vector3d	normalized;

	tube = (t_tube *)object;
	t_direction = vector3d_dot_double(ray.direction_vec, hit_distance);
	point = addition_vector3d(ray.origin, t_direction);
	normal_vector = subtraction_vector3d(point, tube->center);
	normalized = normalize_vector3d(normal_vector);
	return (normalized);
}
