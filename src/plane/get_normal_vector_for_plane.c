/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_plane.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:01:19 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 01:43:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

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
	const double hit_distance,
	const void *object)
{
	t_plane	*plane;

	(void)ray;
	(void)hit_distance;
	plane = (t_plane *)object;
	return (plane->direction_vec);
}
