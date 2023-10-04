/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:04:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:14:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"

/**
 * 平面の色情報を照明比率に基づいて修正し、整数のピクセルカラーとして返す。
 * 
 * lighting_ratio: 現在のピクセル位置の照明比率
 * plane: 平面の情報 (色、法線ベクトルなど)
 * rgb: 照明比率を考慮した後の平面の色情報
 * 
 * 関数は、指定された照明比率に基づいて平面の色を修正し、
 * その修正された色を整数のピクセルカラーとして返す。
 */
int	get_pixel_color_for_plane(
	const void *object,
	const t_ray ray,
	const double ambient_lighting_ratio)
{
	t_plane	*plane;
	t_rgb	rgb;

	plane = (t_plane *)object;
	rgb = reflect_lighting_ratio_in_color(
			plane->color,
			ray.rgb,
			ambient_lighting_ratio,
			ray.lighting_ratio);
	return (convert_rgb_in_int(rgb));
}
