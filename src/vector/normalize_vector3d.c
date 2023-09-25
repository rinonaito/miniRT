/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:20:15 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/25 18:40:07 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <math.h>

/**
 * ベクトルの長さを取得する関数
*/
static double	_get_vector_size(t_vector3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

/**
 * ベクトルを正規化する関数
*/
t_vector3d	normalize_vector3d(t_vector3d v)
{
	const double	vector_size = _get_vector_size(v);
	t_vector3d		normalized_vector;

	normalized_vector.x = v.x / vector_size;
	normalized_vector.y = v.y / vector_size;
	normalized_vector.z = v.z / vector_size;
	return (normalized_vector);
}
