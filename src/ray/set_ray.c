/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:18:57 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 12:03:01 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "config.h"

void	set_ray(
		t_ray *ray,
		const t_camera camera,
		const t_vector3d xyz)
{
	ray->origin = camera.origin;
	ray->direction_vec
		= subtraction_vector3d_xyz(camera.origin, xyz.x, xyz.y, xyz.z);
	ray->direction_vec = normalize_vector3d(ray->direction_vec);
	ray->lighting_ratio = 0;
}
