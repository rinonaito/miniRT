/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lighting_ratio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:06 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/01 22:27:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "light.h"

/**
 * 2つの色（光源の色とレイの色）を混合するための関数
 * 混合の度合いは、指定された照明の比率に基づいている
*/
static t_rgb	_get_ray_color(
	t_rgb ray_rgb,
	t_rgb light_rgb,
	double ray_lighting_ratio,
	double light_lighting_ratio)
{
	int		mixed_red;
	int		mixed_green;
	int		mixed_blue;
	t_rgb	mixed_rgb;
	double	t;

	t = ray_lighting_ratio / (ray_lighting_ratio + light_lighting_ratio);
	mixed_red = (1 - t) * light_rgb.red + t * ray_rgb.red;
	mixed_green = (1 - t) * light_rgb.green + t * ray_rgb.green;
	mixed_blue = (1 - t) * light_rgb.blue + t * ray_rgb.blue;
	mixed_rgb.red = mixed_red;
	mixed_rgb.green = mixed_green;
	mixed_rgb.blue = mixed_blue;
	return (mixed_rgb);
}

/**
 * シーン内の各光源に基づいてレイの照明比率と色を計算する
*/
void	set_lighting_ratio(
	t_ray *ray,
	const t_vector3d point,
	const t_scene scene,
	const t_vector3d normal_vector)
{
	size_t		i;
	double		diffuse;
	double		specular;
	t_vector3d	light_vector;

	i = 0;
	while (i < scene.lights_num)
	{
		light_vector = subtraction_vector3d(point, scene.lights[i].origin);
		if (dot_vector3d(normalize_vector3d(light_vector), normal_vector) > 0.0)
		{
			diffuse = calculate_lighting_ratio(
					normalize_vector3d(light_vector),
					normal_vector,
					scene.lights[i].lighting_ratio);
			specular = get_specular_light(scene.lights[i], normal_vector, point,
					scene.camera.origin);
			ray->rgb = _get_ray_color(
					ray->rgb, scene.lights[i].color,
					ray->lighting_ratio,
					diffuse + specular);
			ray->lighting_ratio += diffuse + specular;
		}
		i++;
	}
}
