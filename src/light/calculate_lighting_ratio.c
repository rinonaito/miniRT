/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting_ratio.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:38 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/15 16:27:51 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "vector.h"
#include <stdbool.h>

static bool	_is_smaller_than_vertical(double cos_theta)
{
	return (cos_theta > VERTICAL);
}

/**
 * 入射ベクトル（ray）と法線ベクトル（normal_vector）から、照明の強度を計算する
 */
double	calculate_lighting_ratio(
	const t_vector3d point_to_light,
	const t_vector3d normal_vector,
	const double lighting_ratio)
{
	double		cos_theta;
	double		dot_result;
	double		dot_length;

	dot_result = dot_vector3d(point_to_light, normal_vector);
	dot_length = get_len_of_vector3d(point_to_light)
		* get_len_of_vector3d(normal_vector);
	cos_theta = dot_result / dot_length;
	if (_is_smaller_than_vertical(cos_theta))
		return (lighting_ratio * cos_theta);
	else
		return (NO_LIGHT_STRENGTH);
}
