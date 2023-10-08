/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_3d.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:50:28 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/08 17:34:54 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

t_vector3d	get_normal_vector_for_3d(
	const t_ray ray,
	const double hit_distance,
	const t_vector3d object_center)
{
	t_vector3d	t_direction;
	t_vector3d	point;
	t_vector3d	normal_vector;
	t_vector3d	normalized;

	t_direction = vector3d_dot_double(ray.direction_vec, hit_distance);
	point = addition_vector3d(ray.origin, t_direction);
	normal_vector = subtraction_vector3d(point, object_center);
	normalized = normalize_vector3d(normal_vector);
	return (normalized);
}
