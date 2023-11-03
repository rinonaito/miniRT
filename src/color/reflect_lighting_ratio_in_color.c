/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_lighting_ratio_in_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:31:22 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:46:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "calculator.h"
#include "config.h"

/**
 * RGBの各色成分（R、G、B）と照明の比率を受け取り、照明の比率を反映した色成分を返す
*/
static int	_get_each_color_element(
	const int object_rgb,
	const double lighting_ratio,
	const int light_rgb)
{
	int	return_color;

	return_color
		= object_rgb * light_rgb * lighting_ratio / MAX_COLOR;
	if (return_color > MAX_COLOR)
		return (MAX_COLOR);
	return (return_color);
}

/**
 * オブジェクトのRGBとライトのRGBを使って、照明の効果が反映されたカラーを計算する
 * 戻り値のcolorは元のオブジェクトの色に照明の色を反映した新しいRGB色
*/
t_rgb	reflect_lighting_ratio_in_color(
	const t_rgb object_rgb,
	const t_rgb light_rgb,
	const double lighting_ratio)
{
	t_rgb	color;

	color.red = _get_each_color_element(
			object_rgb.red,
			lighting_ratio,
			light_rgb.red);
	color.green = _get_each_color_element(
			object_rgb.green,
			lighting_ratio,
			light_rgb.green);
	color.blue = _get_each_color_element(
			object_rgb.blue,
			lighting_ratio,
			light_rgb.blue);
	return (color);
}
