/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_plane.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:01:19 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 14:19:43 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"

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
	const void *object)
{
	t_plane	*plane;

	plane = (t_plane *)object;
	return (get_normal_vector_for_2d(ray, plane->direction_vec));
}