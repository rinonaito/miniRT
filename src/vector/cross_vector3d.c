/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_vector3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:07:53 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/13 17:45:25 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/**
 * ベクトルの外積（クロス積）を求める関数
 * 
 * 外積により、2つのベクトルに対して垂直なベクトルが求められる
*/
t_vector3d	cross_vector3d(const t_vector3d a, const t_vector3d b)
{
	t_vector3d	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}
