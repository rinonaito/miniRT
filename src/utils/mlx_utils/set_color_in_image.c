/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/25 19:46:57 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "sphere.h"
#include "mlx_utils.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>

void	set_color_in_image(
	t_ray ray,
	t_vector2d xy,
	t_mlx_data *mlx_data,
	t_scene scene)
{
	size_t	i;
	ssize_t	j;

	i = 0;
	j = -1;
	while (i < scene.spheres_num)
	{
		if (hit_sphere(ray, scene.spheres[i].center,
				scene.spheres[i].diameter / 2) > 0)
			j = i;
		i++;
	}
	if (j != -1)
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y,
			create_color(scene.spheres[j].color));
	else
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y, 0x000000);
}
