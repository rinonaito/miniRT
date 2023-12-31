/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lighting_ratio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:06 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 19:53:50 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "light.h"
#include "config.h"
#include "init.h"
#include <stdbool.h>

/**
 * 2つの色（光源の色とレイの色）を混合するための関数
 * 混合の度合いは、指定された照明の比率に基づいている
*/
static t_rgb	_get_ray_color(
	const t_rgb ray_rgb,
	const t_rgb light_rgb,
	const double ray_lighting_ratio,
	const double light_lighting_ratio)
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

static bool	_is_smaller_than_vertical(
	const t_vector3d light_vector,
	const t_vector3d normal_vector)
{
	return (dot_vector3d(light_vector, normal_vector) > VERTICAL);
}

static t_ray	_get_spot_light_ray(
		const t_vector3d light_origin,
		t_vector3d point,
		const t_ambient_lighting ambient)
{
	t_ray			spot_light_ray;
	t_vector3d		spot_light_ray_direction;
	const double	thickness = 1.0 / 512.0;

	spot_light_ray_direction = normalize_vector3d(
			subtraction_vector3d(light_origin, point));
	point = addition_vector3d(point,
			vector3d_dot_double(spot_light_ray_direction, thickness));
	set_ray(&spot_light_ray, point, light_origin, ambient);
	return (spot_light_ray);
}

/**
 * シーン内の各光源に基づいてレイの照明比率と色を計算する
 * diffuse : 拡散反射光の照明率
 * specular: 鏡面反射光の照明率
*/
void	set_lighting_ratio(
	t_ray *ray,
	const t_vector3d original_point,
	const t_scene scene,
	const t_vector3d normal_vector)
{
	size_t		i;
	double		diffuse;
	double		specular;
	t_ray		spot_light_ray;

	i = 0;
	while (i < scene.lights_num)
	{
		spot_light_ray = _get_spot_light_ray(
				scene.lights[i].origin, original_point, scene.ambient);
		if (is_hit_by_spot_light(
				spot_light_ray, scene, original_point, scene.lights[i])
			&& _is_smaller_than_vertical(
				spot_light_ray.direction_vec, normal_vector))
		{
			diffuse = calculate_lighting_ratio(spot_light_ray.direction_vec,
					normal_vector, scene.lights[i].lighting_ratio);
			specular = get_specular_lighting_ratio(scene.lights[i],
					normal_vector, original_point, scene.camera.origin);
			ray->rgb = _get_ray_color(ray->rgb, scene.lights[i].color,
					ray->lighting_ratio, diffuse + specular);
			ray->lighting_ratio += (diffuse + specular);
		}
		i++;
	}
}
