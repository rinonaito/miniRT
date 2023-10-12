/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:04 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/12 22:55:54 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include "mlx_utils.h"
#include "calculator.h"
#include "config.h"
#include "vector.h"
#include <math.h>
#include <stdbool.h>

/**
 * 焦点距離を取得する
 * 
 * angle_radians→角度をラジアンに変換したもの（π / 180.0）
 * focal_len→焦点距離
*/
static double	_get_focal_len(double fov)
{
	double	theta;
	double	angle_radians;
	double	focal_len;

	theta = fov / HALF_ANGLE_DIVISOR;
	angle_radians = theta * M_PI / HALF_FULL_DEGREE;
	focal_len = (NORMALIZED_WIDTH / HALF_FACTOR) / tan(angle_radians);
	return (focal_len);
}

static t_vector3d	_get_right_vector(t_vector3d camera_dir)
{
	t_vector3d	y;
	t_vector3d	right_vector;

	set_vector3d(&y, 0.0, 1.0, 0.0);
	right_vector = normalize_vector3d(cross_vector3d(y, camera_dir));
	if (isnan(right_vector.x))
	{
		set_vector3d(&y, 0.0, 0.0, 1.0);
		right_vector = normalize_vector3d(cross_vector3d(y, camera_dir));
	}
	return (right_vector);
}

static void	_set_view_port_info(t_vector3d *view_port, const t_camera camera)
{
	view_port[CENTER] = addition_vector3d(camera.origin,
			vector3d_dot_double(camera.direction_vec,
				_get_focal_len(camera.fov)));
	view_port[RIGHT] = _get_right_vector(camera.direction_vec);
	view_port[DOWN] = normalize_vector3d(
			cross_vector3d(camera.direction_vec, view_port[RIGHT]));
}

static void	_set_view_port_xyz(
			t_vector3d *xyz,
			const t_vector2d uv,
			const t_scene *scene,
			const t_vector3d *view_port)
{
	const double	aspect_ratio = (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT;

	xyz->x = scene->camera.origin.x + scale_to_minus_one_to_one(
			(double)uv.x / (SCREEN_WIDTH - 1.0), false);
	xyz->y = (scene->camera.origin.y + scale_to_minus_one_to_one(
				(double)uv.y / (SCREEN_HEIGHT - 1.0), false))
		/ aspect_ratio;
	xyz->z = view_port[CENTER].z
		+ view_port[RIGHT].z * (xyz->x - view_port[CENTER].x)
		+ view_port[DOWN].z * (xyz->y - view_port[CENTER].y);
}

/**
 * uv座標 ：screenの2次元座標
 *	(範囲： 0 <= u <= SCREEN_WIDTH, 0 <= v <= SCREEN_HEIGHT)
 * xyz座標：scene空間内の3次元座標
 * 	(範囲：-1.0 <= x <= 1.0, -1.0 <= y <= 1.0, -1.0 <= z <= 1.0)
 * uv座標をscene空間上に配置するため、uvの範囲をxyzの範囲(-1.0 ~ 1.0)へ変更したい
 * → 2.0 * ((double)uv.x / SCREEN_WIDTH により 0.0 ~ 1.0 → -1.0 ~ 1.0へ範囲変更
 *
 * aspect_ratio:スクリーンの縦横比が画像へ影響しないようにする 
*/
void	make_image(t_mlx_data *mlx_data, const t_scene *scene)
{
	t_vector3d		xyz;
	t_vector2d		uv;
	t_ray			ray;
	t_vector3d		view_port[3];

	_set_view_port_info(view_port, scene->camera);
	uv.y = SCREEN_HEIGHT - 1;
	while (uv.y >= 0)
	{
		uv.x = 0;
		while (uv.x < SCREEN_WIDTH)
		{
			_set_view_port_xyz(&xyz, uv, scene, view_port);
			set_ray(&ray, scene->camera.origin, xyz);
			my_mlx_pixel_put(mlx_data, (int)uv.x, (SCREEN_HEIGHT - 1)
				- (int)uv.y,
				get_pixel_color(&ray, xyz, *scene));
			uv.x++;
		}
		uv.y--;
	}
}
