/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_circle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naitorino <naitorino@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:25:48 by naitorino         #+#    #+#             */
/*   Updated: 2023/10/06 20:35:03 by naitorino        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"

int	get_pixel_color_for_circle(
	const void *object,
	const t_ray ray,
	const double ambient_lighting_ratio)
{
	t_circle	*circle;

	circle = (t_circle *)object;
	return (
		get_pixel_color_for_object(
			circle->color,
			ray.rgb,
			ambient_lighting_ratio,
			ray.lighting_ratio)
	);
}
