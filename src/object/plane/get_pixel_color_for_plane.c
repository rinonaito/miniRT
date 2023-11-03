/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:04:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 19:50:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"
#include "object.h"
#include "config.h"

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
	const t_ray ray)
{
	t_plane	*plane;

	plane = (t_plane *)object;
	return (get_pixel_color_for_object(
			plane->color,
			ray.rgb,
			ray.lighting_ratio)
	);
}
