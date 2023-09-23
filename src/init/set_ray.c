/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:18:57 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/23 22:23:48 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	set_ray(
		t_ray *ray,
		t_vector3d origin,
		t_vector2d uv,
		double focal_len)
{
	ray->origin = origin;
	ray->direction_vec.x = origin.x - uv.x;
	ray->direction_vec.y = origin.y - uv.y;
	ray->direction_vec.z = focal_len;
}
