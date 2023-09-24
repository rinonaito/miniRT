/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:18:57 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 16:05:06 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

void	set_ray(
		t_ray *ray,
		t_vector3d origin,
		t_vector2d uv,
		double focal_len)
{
	ray->origin = origin;
	ray->direction_vec = subtraction_vector3d_xyz(origin, uv.x, uv.y, focal_len);
}
