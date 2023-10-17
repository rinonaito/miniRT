/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_3d.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:50:28 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 21:35:03 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"
#include <stdbool.h>

/**
 * 3次元図形の法線ベクトルを取得する
 * 法線ベクトルとカメラの方向ベクトルが同方向を向く場合、
 * 法線ベクトルを逆にする
*/
t_vector3d	get_normal_vector_for_3d(
	const t_ray ray,
	const t_vector3d object_center)
{
	t_vector3d	t_direction;
	t_vector3d	point;
	t_vector3d	normal_vector;
	t_vector3d	normalized;

	t_direction = vector3d_dot_double(ray.direction_vec, ray.hit_distance);
	point = addition_vector3d(ray.origin, t_direction);
	normal_vector = subtraction_vector3d(point, object_center);
	if (camera_is_inside_of_object(normal_vector, ray.direction_vec))
		normal_vector = subtraction_vector3d(object_center, point);
	normalized = normalize_vector3d(normal_vector);
	return (normalized);
}
