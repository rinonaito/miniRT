/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specular_lighting_ratio.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:30 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/15 17:46:04 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "vector.h"
#include "light.h"
#include <math.h>

/**
 * 物体の表面上の点での鏡面反射の強さを計算する
 * 
 * incident_light			:入射光のベクトル
 * normal_vector			:法線ベクトル
 * point					:3D空間上の点を示すベクトル
 * camera_origin			:カメラ(視点)の原点を示すベクトル
 * reflect_light			:反射光のベクトル
 * inverse_camera_vector	:指定された点からカメラの原点に向かう方向のベクトル(opint → camera_origin)
 */
double	get_specular_lighting_ratio(
			t_light light,
			t_vector3d normal_vector,
			t_vector3d point,
			t_vector3d camera_origin)
{
	t_vector3d	incident_light;
	t_vector3d	reflect_light;
	t_vector3d	inverse_camera_vector;
	double		lighting_ratio;

	incident_light = subtraction_vector3d(point, light.origin);
	reflect_light = subtraction_vector3d(incident_light,
			vector3d_dot_double(normal_vector,
				SECOND_COEFFICIENT * dot_vector3d(incident_light,
					normal_vector)));
	inverse_camera_vector = normalize_vector3d(
			subtraction_vector3d(camera_origin, point));
	lighting_ratio = calculate_lighting_ratio(reflect_light,
			inverse_camera_vector, light.lighting_ratio);
	if (lighting_ratio == NO_LIGHT_STRENGTH)
		return (NO_LIGHT_STRENGTH);
	return (pow(lighting_ratio, REFLECT_STRENGTH));
}
