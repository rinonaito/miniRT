/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:18:57 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 20:25:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

void	set_ray(
		t_ray *ray,
		const t_vector3d origin,
		const t_vector2d uv,
		const double focal_len)
{
	ray->origin = origin;
	ray->direction_vec
		= subtraction_vector3d_xyz(origin, uv.x, uv.y, focal_len);
	ray->direction_vec = normalize_vector3d(ray->direction_vec);
}
