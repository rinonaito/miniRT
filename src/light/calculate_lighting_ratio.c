/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting_ratio.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:38 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/01 16:05:23 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "vector.h"

/**
 * 入射ベクトル（ray）と法線ベクトル（normal_vector）から、照明の強度を計算する
 */
double	calculate_lighting_ratio(
	const t_vector3d ray,
	const t_vector3d normal_vector,
	const double lighting_ratio)
{
	double		cos_theta;
	double		dot_result;
	double		dot_length;

	dot_result = dot_vector3d(ray, normal_vector);
	dot_length = get_len_of_vector3d(ray)
		* get_len_of_vector3d(normal_vector);
	cos_theta = dot_result / dot_length;
	if (cos_theta > NO_LIGHT_STRENGTH)
		return (lighting_ratio * cos_theta);
	else
		return (NO_LIGHT_STRENGTH);
}
