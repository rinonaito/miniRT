/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_sphere.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:22:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/03 01:19:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

/**
 * 正規化した球の法線ベクトルを返す
 * t_direction: 正規化されたレイの方向ベクトルに、球表面に達する力を掛けたベクトル
 * point: 球表面上のポイントの位置ベクトル(point = origin + t * direction)
 * normal_vector: 法線ベクトル(normal_vector = point - center)
 * normalized: 正規化した法線ベクトル
*/
t_vector3d	get_normal_vector_for_sphere(
	const t_ray ray,
	const double hit_distance,
	const void *object)
{
	t_sphere	*sphere;
	t_vector3d	t_direction;
	t_vector3d	point;
	t_vector3d	normal_vector;
	t_vector3d	normalized;

	sphere = (t_sphere *)object;
	t_direction = vector3d_dot_double(ray.direction_vec, hit_distance);
	point = addition_vector3d(ray.origin, t_direction);
	normal_vector = subtraction_vector3d(point, sphere->center);
	normalized = normalize_vector3d(normal_vector);
	return (normalized);
}
