/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_sphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:45:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"

int	get_pixel_color_for_sphere(
	const void *object,
	const t_ray ray,
	const double ambient_lighting_ratio)
{
	t_sphere	*sphere;
	t_rgb		rgb;

	sphere = (t_sphere *)object;
	rgb = reflect_lighting_ratio_in_color(
			sphere->color,
			ray.rgb,
			ambient_lighting_ratio,
			ray.lighting_ratio);
	return (convert_rgb_in_int(rgb));
}
