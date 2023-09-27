/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_sphere.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:22:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 22:05:54 by rnaito           ###   ########.fr       */
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
	t_ray ray,
	double hit_distance,
	t_vector3d center)
{
	t_vector3d	t_direction;
	t_vector3d	point;
	t_vector3d	normal_vector;
	t_vector3d	normalized;

	t_direction = vector3d_dot_double(ray.direction_vec, hit_distance);
	point = addition_vector3d(ray.origin, t_direction);
	normal_vector = subtraction_vector3d(point, center);
	normalized = normalize_vector3d(normal_vector);
	return (normalized);
}
