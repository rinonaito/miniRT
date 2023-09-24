/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:04 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 20:18:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "init.h"
#include "mlx_utils.h"
#include <math.h>

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
	angle_radians = theta * M_PI / 180.0;
	focal_len = tan(angle_radians);
	return (focal_len);
}

/**
 * xy.x / SCREEN_WIDTH だと0.0 ~ 1.0になってしまうため、
 * 2.0 * ((double)xy.x / SCREEN_WIDTH　とすることで-1.0 ~ 1.0になる。
*/
void	make_image(t_mlx_data *mlx_data, t_scene *scene)
{
	t_vector2d		uv;
	t_vector2d		xy;
	t_ray			ray;
	const double	focal_len = _get_focal_len(scene->camera.fov);
	const double	aspect_ratio = (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT;

	xy.y = 0;
	while (xy.y < SCREEN_HEIGHT)
	{
		xy.x = 0;
		while (xy.x < SCREEN_WIDTH)
		{
			uv.x = (UV_SCALE * ((double)xy.x / SCREEN_WIDTH) - UV_OFFSET)
				* aspect_ratio;
			uv.y = UV_SCALE * ((double)xy.y / SCREEN_HEIGHT) - UV_OFFSET;
			set_ray(&ray, scene->camera.origin, uv, focal_len);
			set_color_in_image(ray, xy, mlx_data, *scene);
			xy.x++;
		}
		xy.y++;
	}
}
