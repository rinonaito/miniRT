/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_lighting_ratio_in_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:31:22 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/01 20:54:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "calculator.h"
#include "config.h"

//TODO:削除予定
//-1.0 ~ 1.0 → 0 ~ 255へ変換する
// static int	_change_scale_for_color(const double x)
// {
// 	return (scale_to_zero_to_one(x) * 255.999);
// }

static int	_get_each_color_element(
	const int rgb,
	const double lighting_ratio)
{
	int	return_color;

	if (rgb <= MIN_COLOR)
		return (MIN_COLOR);
	return_color
		= rgb * lighting_ratio;
	if (return_color >= MAX_COLOR)
		return (MAX_COLOR);
	return (return_color);
}

t_rgb	reflect_lighting_ratio_in_color(
	const t_rgb object_rgb,
	const t_rgb light_rgb,
	const double ambient_lighting_ratio,
	const double direct_lighting_ratio)
{
	t_rgb	color;

	(void)light_rgb;
	color.red = _get_each_color_element(
			object_rgb.red,
			ambient_lighting_ratio
			+ direct_lighting_ratio * light_rgb.red / MAX_COLOR);
	color.green = _get_each_color_element(
			object_rgb.green,
			ambient_lighting_ratio
			+ direct_lighting_ratio * light_rgb.green / MAX_COLOR);
	color.blue = _get_each_color_element(
			object_rgb.blue,
			ambient_lighting_ratio
			+ direct_lighting_ratio * light_rgb.blue / MAX_COLOR);
	return (color);
}
