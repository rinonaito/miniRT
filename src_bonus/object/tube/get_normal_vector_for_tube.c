/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_tube.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:17 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/03 19:45:40 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

t_vector3d	get_normal_vector_for_tube(
	const t_ray ray,
	const t_vector3d point,
	const void *object)
{
	t_tube		*tube;
	t_vector3d	bottom_center;
	t_vector3d	center_to_point;
	t_vector3d	projection_on_axis;
	t_vector3d	normal_vector;

	tube = (t_tube *)object;
	bottom_center = subtraction_vector3d(tube->center,
			vector3d_dot_double(tube->direction_vec, tube->height / 2.0));
	center_to_point = subtraction_vector3d(point, bottom_center);
	projection_on_axis = get_projection_vector(
			tube->direction_vec, center_to_point);
	normal_vector = subtraction_vector3d(center_to_point, projection_on_axis);
	if (camera_is_inside_of_object(normal_vector, ray.direction_vec))
		normal_vector = subtraction_vector3d(
				projection_on_axis, center_to_point);
	return (normalize_vector3d(normal_vector));
}
