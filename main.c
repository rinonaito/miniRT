/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/23 18:20:55 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "types.h"
#include "config.h"
#include "src.h"

int	main(void)
{
	t_mlx_data	mlx_data;
	t_sphere	sphere;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT, TITLE);
	mlx_data.image = mlx_new_image(mlx_data.mlx, WIDTH, HEIGHT);
	mlx_data.addr = mlx_get_data_addr(mlx_data.image, &mlx_data.bits_per_pixel,  &mlx_data.line_length, &mlx_data.endian);
	mlx_loop(mlx_data.mlx);
	///
	sphere.coordinate.x = 0.0;
	sphere.coordinate.y = 0.0;
	sphere.coordinate.z = 20.6;
	sphere.diameter = 12.6;
	sphere.color.red = 10;
	sphere.color.green = 0;
	sphere.color.blue = 255;
	//
	make_image(&mlx_data, &sphere);
}
