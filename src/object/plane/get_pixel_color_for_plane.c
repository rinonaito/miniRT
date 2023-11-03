/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:04:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/02 21:03:01 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"
#include "object.h"
#include "config.h"
#include <math.h>

static t_rgb	_get_plane_color_for_checkerboard(const t_plane plane)
{
	int			checker_x;
	int			checker_y;
	t_rgb		opposite_color;

	checker_x = (int)(floor(plane.hit_point.x / CHECKER_SIZE)) % 2;
	checker_y = (int)(floor(plane.hit_point.y / CHECKER_SIZE)) % 2;
	if (pow(checker_x, 2) == pow(checker_y, 2))
	{
		opposite_color.red = MAX_COLOR - plane.color.red;
		opposite_color.green = MAX_COLOR - plane.color.green;
		opposite_color.blue = MAX_COLOR - plane.color.blue;
		return (opposite_color);
	}
	return (plane.color);
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
 //TODO:pointを削除する
int	get_pixel_color_for_plane(
	const void *object,
	const t_ray ray,
	t_vector3d	point)
{
	t_plane	*plane;
	t_rgb	color;

	(void)point;
	plane = (t_plane *)object;
	if (plane->texture == CHECKER)
	{
		color = _get_plane_color_for_checkerboard(*plane);
	}
	else
		color = plane->color;
	return (get_pixel_color_for_object(
			color,
			ray.rgb,
			ray.lighting_ratio));
}
