/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_tube.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:39 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 15:20:29 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "color.h"

int	get_pixel_color_for_tube(
	const void *object,
	const t_ray ray,
	const double ambient_lighting_ratio)
{
	t_tube	*tube;
	t_rgb	rgb;

	tube = (t_tube *)object;
	rgb = reflect_lighting_ratio_in_color(
			tube->color,
			ray.rgb,
			ambient_lighting_ratio,
			ray.lighting_ratio);
	return (convert_rgb_in_int(rgb));
}
