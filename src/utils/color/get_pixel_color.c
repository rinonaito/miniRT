/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:35:15 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/28 21:31:57 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "calculator.h"

//-1.0 ~ 1.0 → 0 ~ 255へ変換する
static int	change_scale_for_color(double x)
{
	return (scale_to_zero_to_one(x) * 255.999);
}

t_rgb	get_pixel_color(t_rgb original_color, t_vector3d nomal_vector, double lighting_ratio)
{
	t_rgb	color;

	color.red = original_color.red + change_scale_for_color(nomal_vector.x) + lighting_ratio;
	color.green = original_color.green + change_scale_for_color(nomal_vector.y) + lighting_ratio;
	color.blue = original_color.blue + change_scale_for_color(nomal_vector.z) + lighting_ratio;
	return (color);
}
