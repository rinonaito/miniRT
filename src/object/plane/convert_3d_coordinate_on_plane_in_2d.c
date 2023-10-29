/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_3d_coordinate_on_plane_in_2d.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:36:56 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/29 21:42:24 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <math.h>

/**
 * 空間内の3d座標から、2d座標へ変換する
 * 
 * 物体交点における法線ベクトルについて、x, y, zの中で最も大きい要素を定める。
 * その要素の軸に対して、交点の座標を射影することで3d→2d座標への変換ができる。
 */
t_vector2d	convert_3d_coordinate_on_plane_in_2d(
		const t_vector3d coordinate_3d,
		const t_vector3d normal)
{
	t_vector2d	coordinate_2d;

	if (fabs(normal.x) > fabs(normal.y)
		&& fabs(normal.x) > fabs(normal.z))
	{
		coordinate_2d.x = coordinate_3d.y;
		coordinate_2d.y = coordinate_3d.z;
	}
	else if (fabs(normal.y) > fabs(normal.z))
	{
		coordinate_2d.x = coordinate_3d.x;
		coordinate_2d.y = coordinate_3d.z;
	}
	else
	{
		coordinate_2d.x = coordinate_3d.x;
		coordinate_2d.y = coordinate_3d.y;
	}
	return (coordinate_2d);
}
