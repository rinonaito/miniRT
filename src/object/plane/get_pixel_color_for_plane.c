/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:04:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/20 16:45:36 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"
#include "object.h"
#include "config.h"
#include <math.h>

/**
 * 空間内の3d座標から、2d座標へ変換する
 * 
 * 物体交点における法線ベクトルについて、x, y, zの中で最も大きい要素を定める。
 * その要素の軸に対して、交点の座標を射影することで3d→2d座標への変換ができる。
 */
static t_vector2d	_convert_coordinate_in_2d(
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

static t_rgb	_get_plane_color_for_checkerboard(
		const t_vector3d coordinate_3d,
		const t_vector3d normal,
		const t_rgb base_color)
{
	t_vector2d	coordinate_2d;
	int			checker_x;
	int			checker_y;
	t_rgb		opposite_color;

	coordinate_2d = _convert_coordinate_in_2d(coordinate_3d, normal);
	checker_x = (int)(floor(coordinate_2d.x / CHECKER_SIZE)) % 2;
	checker_y = (int)(floor(coordinate_2d.y / CHECKER_SIZE)) % 2;
	if (pow(checker_x, 2) == pow(checker_y, 2))
	{
		opposite_color.red = 255 - base_color.red;
		opposite_color.green = 255 - base_color.green;
		opposite_color.blue = 255 - base_color.blue;
		return (opposite_color);
	}
	return (base_color);
}

/**
 * 平面の色情報を照明比率に基づいて修正し、整数のピクセルカラーとして返す。
 * 
 * lighting_ratio: 現在のピクセル位置の照明比率
 * plane: 平面の情報 (色、法線ベクトルなど)
 * 
 * 関数は、指定された照明比率に基づいて平面の色を修正し、
 * その修正された色を整数のピクセルカラーとして返す。
 */
int	get_pixel_color_for_plane(
	const void *object,
	const t_ray ray,
	t_vector3d	point)
{
	t_plane	*plane;
	t_rgb	color;

	plane = (t_plane *)object;
	if (plane->texture == CHECKER)
	{
		color = _get_plane_color_for_checkerboard(
				point, plane->direction_vec, plane->color);
	}
	else
		color = plane->color;
	return (get_pixel_color_for_object(
			color,
			ray.rgb,
			ray.lighting_ratio));
}
