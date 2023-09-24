/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:04 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 14:45:09 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "init.h"
#include <math.h>

/**
 * 焦点距離を取得する
*/
static double	_get_focal_len(int fov)
{
	double	angle_degree;
	double	angle_radians;
	double	focal_len;

	angle_degree = fov / 2;
	angle_radians = angle_degree * M_PI / 180.0;
	focal_len = tan(angle_radians);
	return (focal_len);
}

void	make_image(t_mlx_data *mlx_data, t_scene *scene)
{
	t_vector2d	uv;
	t_vector2d	xy;
	t_ray		ray;
	double		focal_len;

	xy.y = 0;
	focal_len = _get_focal_len(scene->camera.fov);
	while (xy.y < SCREEN_HEIGHT)
	{
		xy.x = 0;
		while (xy.x < SCREEN_WIDTH)
		{
			(void)mlx_data;
			uv.x = (double)xy.x / (SCREEN_WIDTH - 1);
			uv.y = (double)xy.y / (SCREEN_HEIGHT - 1);
			set_ray(&ray, scene->camera.origin, uv, focal_len);
			set_ray_color(ray, mlx_data, scene);
			xy.x++;
		}
		xy.y++;
	}
}
