/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:04 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/18 21:36:17 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include "mlx_utils.h"
#include "calculator.h"
#include "config.h"
#include "vector.h"
#include "src.h"
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

static bool	_camera_dir_is_horizontal_to_y(t_vector3d camera_dir, t_vector3d y)
{
	double	result;

	result = dot_vector3d(camera_dir, y);
	if (result == 1.0 || result == -1.0)
		return (true);
	return (false);
}

/**
 * ビューポート関連の以下3つの情報を、パラメータview_portへ格納する
 * ⑴ view_port[CENTER]：ビューポートの中心座標
 * ⑵ view_port[RIGHT]：ビューポート上を右方向へ移動する方向ベクトル
 * ⑶ view_port[DOWN]：ビューポート上を下方向へ移動する方向ベクトル
*/
static void	_set_view_port_info(t_vector3d *view_port, const t_camera camera)
{
	t_vector3d	x;
	t_vector3d	y;

	view_port[CENTER] = addition_vector3d(camera.origin,
			vector3d_dot_double(camera.direction_vec,
				_get_focal_len(camera.fov)));
	set_vector3d(&y, 0.0, 1.0, 0.0);
	if (_camera_dir_is_horizontal_to_y(camera.direction_vec, y))
	{
		set_vector3d(&x, 1.0, 0.0, 0.0);
		view_port[DOWN] = normalize_vector3d(
				cross_vector3d(camera.direction_vec, x));
		view_port[RIGHT] = normalize_vector3d(
				cross_vector3d(camera.direction_vec, view_port[DOWN]));
	}
	else
	{
		view_port[RIGHT] = normalize_vector3d(
				cross_vector3d(camera.direction_vec, y));
		view_port[DOWN] = normalize_vector3d(
				cross_vector3d(camera.direction_vec, view_port[RIGHT]));
	}
}

/**
 * ビューポート上の座標を、３次元空間内のxyz座標へ変換する
 * 
 * uv座標 ：view_portの2次元座標
 *	(範囲： 0 <= u <= (VIEW_PORT_WIDTH-1), 0 <= v <= (VIEW_PORT_HEIGHT-1))
 * xyz座標：view_port空間内の3次元座標
 * 	(範囲：-1.0 <= x <= 1.0, -1.0 <= y <= 1.0, -1.0 <= z <= 1.0)
*/
static void	_set_view_port_xyz(
			t_vector3d *xyz,
			const t_vector2d uv,
			const t_vector3d *view_port)
{
	const double	aspect_ratio
		= (double)VIEW_PORT_WIDTH / (double)VIEW_PORT_HEIGHT;
	const double	scale_downed_x = scale_to_minus_one_to_one(
			(double)uv.x / (VIEW_PORT_WIDTH - 1.0));
	const double	scale_downed_y = scale_to_minus_one_to_one(
			(double)uv.y / (VIEW_PORT_HEIGHT - 1.0)) / aspect_ratio;

	xyz->x = view_port[CENTER].x
		+ view_port[RIGHT].x * scale_downed_x
		+ view_port[DOWN].x * scale_downed_y;
	xyz->y = view_port[CENTER].y
		+ view_port[RIGHT].y * scale_downed_x
		+ view_port[DOWN].y * scale_downed_y;
	xyz->z = view_port[CENTER].z
		+ view_port[RIGHT].z * scale_downed_x
		+ view_port[DOWN].z * scale_downed_y;
}

/**
 * uv座標 ：ビューポート上の2次元座標
 * xyz座標：3次元空間内の3次元座標
*/
void	make_image(t_mlx_data *mlx_data, const t_scene *scene)
{
	t_vector3d		xyz;
	t_vector2d		uv;
	t_ray			ray;
	t_vector3d		view_port[3];

	_set_view_port_info(view_port, scene->camera);
	uv.y = VIEW_PORT_HEIGHT - 1;
	while (uv.y >= 0)
	{
		uv.x = 0;
		while (uv.x < VIEW_PORT_WIDTH)
		{
			_set_view_port_xyz(&xyz, uv, view_port);
			set_ray(&ray, scene->camera.origin, xyz, scene->ambient);
			my_mlx_pixel_put(mlx_data, (int)uv.x, (VIEW_PORT_HEIGHT - 1)
				- (int)uv.y, get_pixel_color(&ray, *scene));
			uv.x++;
		}
		uv.y--;
	}
}
