/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_3d_coordinate_on_plane_in_2d.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:36:56 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/02 23:27:54 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"
#include "types.h"
#include <math.h>

/**
 * 空間内の3d座標から、2d座標へ変換する
 * 
 * 物体交点における法線ベクトルについて、x, y, zの中で最も大きい要素を定める。
 * その要素の軸に対して、交点の座標を射影することで3d→2d座標への変換ができる。
 */

t_vector2d	convert_3d_coordinate_on_plane_in_2d(
		const t_vector3d basis_vec1,
		const t_vector3d basis_vec2,
		const t_vector3d coordinate_3d)
{
	t_vector2d	coordinate_2d;

	coordinate_2d.x = dot_vector3d(coordinate_3d, basis_vec1);
	coordinate_2d.y = dot_vector3d(coordinate_3d, basis_vec2);
	return (coordinate_2d);
}
