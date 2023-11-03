/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_sphere.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:22:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/03 12:38:17 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

/**
 * 正規化した球の法線ベクトルを返す
 * t_direction: 正規化されたレイの方向ベクトルに、球表面に達する力を掛けたベクトル
 * point: 球表面上のポイントの位置ベクトル(point = origin + t * direction)
 * normal_vector: 法線ベクトル(normal_vector = point - center)
 * normalized: 正規化した法線ベクトル
*/
t_vector3d	get_normal_vector_for_sphere(
	const t_ray ray,
	const t_vector3d point,
	const void *object,
	const t_bumpmap bumpmap)
{
	t_sphere	*sphere;
	t_vector3d	normal_vector;
	t_vector3d	normalized;

	(void) bumpmap;
	sphere = (t_sphere *)object;
	normal_vector = subtraction_vector3d(point, sphere->center);
	if (camera_is_inside_of_object(normal_vector, ray.direction_vec))
		normal_vector = subtraction_vector3d(sphere->center, point);
	normalized = normalize_vector3d(normal_vector);
	return (normalized);
}
