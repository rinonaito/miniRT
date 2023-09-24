/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 21:40:22 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "sphere.h"
#include "mlx_utils.h"
#include "color.h"

void	set_color_in_image(
	t_ray ray,
	t_vector2d xy,
	t_mlx_data *mlx_data,
	t_scene scene)
{
	if (hit_sphere(ray, scene.spheres[0].center, scene.spheres[0].diameter / 2))
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y, create_color(scene.spheres[0].color));
	else
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y, 0x000000);
}
