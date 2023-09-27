/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 22:18:03 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "sphere.h"
#include "mlx_utils.h"
#include "color.h"
#include "vector.h"
#include "calculator.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>

void	set_color_in_image(
	t_ray ray,
	t_vector2d xy,
	t_mlx_data *mlx_data,
	t_scene scene)
{
	double		hit_distance;
	t_rgb		rgb;
	t_vector3d	normal_vector;

	hit_distance = hit_sphere(ray, scene.spheres[0].center,
			scene.spheres[0].diameter / 2);
	if (hit_distance >= 0.0)
	{
		normal_vector = get_normal_vector_for_sphere(ray, hit_distance,
				scene.spheres[0].center);
		rgb = get_pixel_color(scene.spheres[0].color, normal_vector);
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y,
			convert_rgb_in_int(rgb));
	}
	else
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y, 0x000000);
}
