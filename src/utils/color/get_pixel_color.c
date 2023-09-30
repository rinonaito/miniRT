/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:35:15 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 14:01:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "calculator.h"
#include "config.h"

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

t_rgb	get_pixel_color(
	const t_rgb rgb,
	const double lighting_ratio)
{
	t_rgb	color;

	color.red
		= _get_each_color_element(rgb.red, lighting_ratio);
	color.green
		= _get_each_color_element(rgb.green, lighting_ratio);
	color.blue
		= _get_each_color_element(rgb.blue, lighting_ratio);
	return (color);
}
