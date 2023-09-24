/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:53:14 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 16:26:34 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "sphere.h"
#include "mlx_utils.h"

void	set_color_in_image(t_ray ray, t_vector2d xy, t_mlx_data *mlx_data, t_scene scene)
{
	int	red = 0xFF0000;
	int	blue = 0x0000FF;

	if (hit_sphere(ray, scene.spheres[0].center, scene.spheres[1].diameter / 2))
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y, red);
	else
		my_mlx_pixel_put(mlx_data, (int)xy.x, (int)xy.y, blue);
}
