/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_cone_side.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:03:40 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/06 19:58:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

t_vector3d	get_normal_vector_for_cone_side(
	const t_ray ray,
	const t_vector3d point,
	const void *object,
	const t_bumpmap bumpmap)
{
	t_cone		*cone;
	t_vector3d	bottom_center;
	t_vector3d	center_to_point;
	t_vector3d	projection_on_axis;
	t_vector3d	normal_vector;

	(void) bumpmap;
	cone = (t_cone *)object;
	bottom_center = addition_vector3d(cone->top,
			vector3d_dot_double(cone->direction_vec, cone->height));
	center_to_point = normalize_vector3d(
			subtraction_vector3d(point, bottom_center));
	projection_on_axis = normalize_vector3d(get_projection_vector(
				vector3d_dot_double(cone->direction_vec, -1.0),
				center_to_point));
	normal_vector = subtraction_vector3d(center_to_point, projection_on_axis);
	if (camera_is_inside_of_object(normal_vector, ray.direction_vec))
	{
		normal_vector = subtraction_vector3d(
				projection_on_axis, center_to_point);
	}
	return (normalize_vector3d(normal_vector));
}
