/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_object.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:31:45 by naitorino         #+#    #+#             */
/*   Updated: 2023/10/08 17:34:29 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "color.h"

int	get_pixel_color_for_object(
	t_rgb object_rgb,
	t_rgb ray_rgb,
	double ambient_lighting_ratio,
	double direct_lighting_ratio)
{
	t_rgb	rgb;

	rgb = reflect_lighting_ratio_in_color(
			object_rgb,
			ray_rgb,
			ambient_lighting_ratio,
			direct_lighting_ratio);
	return (convert_rgb_in_int(rgb));
}
