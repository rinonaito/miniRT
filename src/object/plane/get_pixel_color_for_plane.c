/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:04:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/29 21:11:03 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"
#include "object.h"
#include "config.h"
#include <math.h>

static t_rgb	_get_plane_color_for_checkerboard(
		const t_vector3d coordinate_3d,
		const t_vector3d normal,
		const t_rgb base_color)
{
	t_vector2d	coordinate_2d;
	int			checker_x;
	int			checker_y;
	t_rgb		opposite_color;

	coordinate_2d = convert_3d_coordinate_on_plane_in_2d(coordinate_3d, normal);
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
