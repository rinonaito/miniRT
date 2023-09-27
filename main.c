/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/27 21:46:31 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "types.h"
#include "config.h"
#include "src.h"
#include "init.h"
#include "mlx_utils.h"

#include <stdlib.h>

void	init_map(t_scene *scene)
{
	set_vector3d(&scene->camera.origin, 0.0, 0.0, 0.0);
	scene->camera.fov = 90;
	set_vector3d(&scene->camera.direction_vec, -50.0, 0.0, 20.0);
	scene->spheres = malloc(sizeof(t_sphere) * 2);
	scene->spheres[0].center.x = 10.0;
	scene->spheres[0].center.y = 0.0;
	scene->spheres[0].center.z = 10.6;
	scene->spheres[0].diameter = 12.6;
	scene->spheres[0].color.red = 100;
	scene->spheres[0].color.green = 0;
	scene->spheres[0].color.blue = 100;
	scene->spheres[1].center.x = 10.5;
	scene->spheres[1].center.y = 5.5;
	scene->spheres[1].center.z = 10.6;
	scene->spheres[1].diameter = 5.6;
	scene->spheres[1].color.red = 0;
	scene->spheres[1].color.green = 255;
	scene->spheres[1].color.blue = 100;
	scene->spheres_num = 1;
}

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
	init_map(&scene);
	make_image(&mlx_data, &scene);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image, 0, 0);
	mlx_hook(
		mlx_data.win, ON_KEYDOWN, 1L << 0, handle_key_press, (void *)&mlx_data);
	mlx_hook(
		mlx_data.win, ON_DESTROY, 0, handle_window_close, (void *)&mlx_data);
	mlx_loop(mlx_data.mlx);
}
