/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_circle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:25:48 by naitorino         #+#    #+#             */
/*   Updated: 2023/10/20 15:37:40 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"

int	get_pixel_color_for_circle(
	const void *object,
	const t_ray ray,
	const t_vector3d point)
{
	t_circle	*circle;

	(void)point;
	circle = (t_circle *)object;
	return (get_pixel_color_for_object(
			circle->color,
			ray.rgb,
			ray.lighting_ratio)
	);
}
