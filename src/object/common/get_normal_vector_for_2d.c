/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_2d.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:32 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/16 21:41:20 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

/**
 * 2次元図形の法線ベクトルを取得する
 * 法線ベクトルとカメラの方向ベクトルが同方向を向く場合、
 * 法線ベクトルを逆にする
*/
t_vector3d	get_normal_vector_for_2d(
	const t_ray ray,
	t_vector3d object_direction)
{
	(void)ray;
	if (dot_vector3d(object_direction, ray.direction_vec) > 0.0)
		object_direction = vector3d_dot_double(object_direction, -1.0);
	return (normalize_vector3d(object_direction));
}
