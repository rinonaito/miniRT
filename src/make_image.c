/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:04 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 20:44:52 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include "mlx_utils.h"
#include "calculator.h"
#include "config.h"
#include <math.h>
#include <stdbool.h>

/**
 * 焦点距離を取得する
 * 
 * angle_radians→角度をラジアンに変換したもの（π / 180.0）
 * focal_len→焦点距離
*/
static double	_get_focal_len(int fov)
{
	double	theta;
	double	angle_radians;
	double	focal_len;

	theta = fov / HALF_ANGLE_DIVISOR;
	angle_radians = theta * M_PI / HALF_FULL_DEGREE;
	focal_len = (SCREEN_WIDTH / HALF_FACTOR) / tan(angle_radians);
	return (focal_len);
}

/**
 * screenまでの距離を取得し、正規化する（0 ~ 1へスケールダウン）
*/
static double	_get_normalized_focal_len(int fov)
{
	const double	max_focal_len = _get_focal_len(MIN_FOV);
	const double	min_focal_len = _get_focal_len(MAX_FOV);
	const double	focal_len = _get_focal_len(fov);

	return (SCENE_SCALE * focal_len / (max_focal_len - min_focal_len)
		- SCENE_OFFSET);
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
void	make_image(t_mlx_data *mlx_data, t_scene *scene)
{
	t_vector3d		xyz;
	t_vector2d		uv;
	t_ray			ray;
	const double	aspect_ratio = (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT;

//	xyz.z = _get_normalized_focal_len(scene->camera.fov);
	uv.y = SCREEN_HEIGHT - 1;
	while (uv.y >= 0)
	{
		uv.x = 0;
		while (uv.x < SCREEN_WIDTH)
		{
			xyz.x = scale_to_minus_one_to_one(
					(double)uv.x / (SCREEN_WIDTH - 1.0), true);
			xyz.y = scale_to_minus_one_to_one(
					(double)uv.y / (SCREEN_HEIGHT - 1.0), false) / aspect_ratio;
			set_ray(&ray, scene->camera.origin, xyz);
			xyz.z = _get_normalized_focal_len(scene->camera.fov) * ray.direction_vec.z;
	//		printf("ray[%lf, %lf, %lf]\n", ray.direction_vec.x, ray.direction_vec.y, ray.direction_vec.z);
	//		printf("camera[%lf, %lf, %lf]\n", scene->camera.origin.x, scene->camera.origin.y, scene->camera.origin.z);
	//		printf("xyz[%lf, %lf, %lf]\n", xyz.x, xyz.y, xyz.z);
			my_mlx_pixel_put(mlx_data, (int)uv.x, (int)uv.y,
				get_pixel_color(&ray, xyz, *scene));
			uv.x++;
		}
		uv.y--;
	}
}
