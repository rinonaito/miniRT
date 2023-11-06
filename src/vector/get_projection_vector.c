/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_projection_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:42:22 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/06 18:05:19 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

/**
 * 射影ベクトルを取得する関数
 * ベースとなるベクトルに対して、ベースのベクトルと射影をとりたいベクトルとの内積を
 * かけることで、射影ベクトルを取得できる。
 * 
 * t_vector3d base: 射影のベースとなる
 * t_vector3d target: 射影をとりたいベクトル
*/
t_vector3d	get_projection_vector(
	const t_vector3d direction_vec,
	const t_vector3d center_to_point)
{
	return (vector3d_dot_double(
			direction_vec,
			dot_vector3d(center_to_point, direction_vec)));
}
