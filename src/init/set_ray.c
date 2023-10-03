/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:18:57 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/01 20:32:01 by yshimoma         ###   ########.fr       */
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
		= subtraction_vector3d(camera.origin, xyz);
	ray->direction_vec = normalize_vector3d(ray->direction_vec);
	ray->lighting_ratio = 0;
	ray->rgb.red = 0;
	ray->rgb.green = 0;
	ray->rgb.blue = 0;
}
