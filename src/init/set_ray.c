/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:18:57 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 20:43:44 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"

void	set_ray(
		t_ray *ray,
		const t_vector3d origin,
		const t_vector3d xyz)
{
	ray->origin = origin;
	ray->direction_vec
		= normalize_vector3d(subtraction_vector3d(xyz, origin));
	ray->lighting_ratio = 0;
	ray->hit_distance = DBL_MAX;
	ray->hit_object_index = NOT_HIT;
	ray->rgb.red = 0;
	ray->rgb.green = 0;
	ray->rgb.blue = 0;
}
