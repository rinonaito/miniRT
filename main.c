/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/30 12:15:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "types.h"
#include "config.h"
#include "src.h"
#include "init.h"
#include "mlx_utils.h"

//TODO:あとで削除
void	init_map(t_scene *scene);

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
