/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_sphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:45:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 12:36:04 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"
#include "object.h"

/**
 * 球の色情報を照明比率に基づいて修正し、整数のピクセルカラーとして返す。
 * 
 * lighting_ratio: 現在のピクセル位置の照明比率
 * sphere: 球の情報 (色、法線ベクトルなど)
 * rgb: 照明比率を考慮した後の平面の色情報
 * 
 * 関数は、指定された照明比率に基づいて平面の色を修正し、
 * その修正された色を整数のピクセルカラーとして返す。
 */
int	get_pixel_color_for_sphere(
	const void *object,
	const t_ray ray)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	return (get_pixel_color_for_object(
			sphere->color,
			ray.rgb,
			ray.lighting_ratio));
}
