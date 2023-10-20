/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_tube.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:39 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/20 15:38:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "color.h"
#include "object.h"

int	get_pixel_color_for_tube(
	const void *object,
	const t_ray ray,
	const t_vector3d point)
{
	t_tube	*tube;

	(void)point;
	tube = (t_tube *)object;
	return (get_pixel_color_for_object(tube->color,
			ray.rgb,
			ray.lighting_ratio));
}
