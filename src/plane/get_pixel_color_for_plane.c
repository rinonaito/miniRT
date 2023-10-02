/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:04:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:49 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"

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
