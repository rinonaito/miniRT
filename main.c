/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/23 20:09:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "types.h"
#include "config.h"
#include "src.h"
#include "init.h"

#include <stdlib.h>
int	main(void)
{
	t_mlx_data	mlx_data;
	t_scene		scene;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT, TITLE);
	mlx_data.image = mlx_new_image(mlx_data.mlx, WIDTH, HEIGHT);
	mlx_data.addr = mlx_get_data_addr(mlx_data.image, &mlx_data.bits_per_pixel,  &mlx_data.line_length, &mlx_data.endian);
	mlx_loop(mlx_data.mlx);
	///
	set_coordinate(&scene.camera.origin, -50.0, 0.0, 20.0);
	scene.camera.fov = 70;
	set_coordinate(&scene.camera.direction_vec, 0.0, 0.0, 1.0);
	scene.spheres = malloc(sizeof(t_sphere) * 1);
	scene.spheres->center.x = 0.0;
	scene.spheres->center.y = 0.0;
	scene.spheres->center.z = 20.6;
	scene.spheres->diameter = 12.6;
	scene.spheres->color.red = 10;
	scene.spheres->color.green = 0;
	scene.spheres->color.blue = 255;
	//
	make_image(&mlx_data, &scene);
}
