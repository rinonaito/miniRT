/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/24 21:40:23 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "types.h"
#include "config.h"
#include "src.h"
#include "init.h"

#include <stdlib.h>
/**
 * TODO:
 * hit_recordを理解・実装する。
 * 法線を使ったレンダリングを実装する。
*/
int	main(void)
{
	t_mlx_data	mlx_data;
	t_scene		scene;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, TITLE);
	mlx_data.image = mlx_new_image(mlx_data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_data.addr = mlx_get_data_addr(mlx_data.image,
			&mlx_data.bits_per_pixel, &mlx_data.line_length, &mlx_data.endian);
	///
	set_vector3d(&scene.camera.origin, 0.0, 0.0, 0.0);
	scene.camera.fov = 70;
	set_vector3d(&scene.camera.direction_vec, -50.0, 0.0, 20.0);
	scene.spheres = malloc(sizeof(t_sphere) * 1);
	scene.spheres->center.x = 0.0;
	scene.spheres->center.y = 0.0;
	scene.spheres->center.z = 20.6;
	scene.spheres->diameter = 12.6;
	scene.spheres->color.red = 100;
	scene.spheres->color.green = 0;
	scene.spheres->color.blue = 100;
	//
	make_image(&mlx_data, &scene);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image, 0, 0);	
	mlx_loop(mlx_data.mlx);
}
