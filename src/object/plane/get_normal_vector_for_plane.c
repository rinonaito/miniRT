/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_plane.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:01:19 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 12:40:18 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"
#include "vector.h"
#include "stdbool.h"

static bool	_is_first_hit(t_vector3d basis_vec1)
{
	if (basis_vec1.x == 0
		&& basis_vec1.y == 0
		&& basis_vec1.z == 0)
		return (true);
	else
		return (false);
}

/**
 * 平面の法線ベクトルを返す
 * 
 * 平面は平面全体で一貫した法線ベクトルを持っているため、
 * この関数は平面オブジェクトからその法線ベクトルを直接返します。
 * 
 * rayとhit_distanceはこの関数内で使用されていないが、
 * 関数のプロトタイプを統一するために引数として保持しています。
 * 
 * plane: 平面の情報（法線ベクトルなど）
 */
t_vector3d	get_normal_vector_for_plane(
	const t_ray ray,
	const t_vector3d point,
	const void *object,
	const t_bumpmap bumpmap)
{
	t_plane		*plane;
	t_vector3d	normal_vec;

	(void)point;
	plane = (t_plane *)object;
	normal_vec = get_normal_vector_for_2d(ray, plane->direction_vec);
	if (plane->texture != NORMAL)
	{
		if (_is_first_hit(plane->basis_vec1))
		{
			plane->basis_vec1 = normalize_vector3d(
					subtraction_vector3d(point, plane->coordinate));
			plane->basis_vec2 = normalize_vector3d(
					cross_vector3d(normal_vec, plane->basis_vec1));
		}
		plane->hit_point = convert_3d_coordinate_on_plane_in_2d(
				plane->basis_vec1,
				plane->basis_vec2,
				point);
	}
	if (plane->texture == BUMP)
		normal_vec = get_normal_vector_with_bump(
				plane->hit_point, normal_vec, bumpmap);
	return (normal_vec);
}
