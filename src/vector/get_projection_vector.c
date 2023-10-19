/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_projection_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:42:22 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/19 20:50:10 by rnaito           ###   ########.fr       */
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
	const t_vector3d base,
	const t_vector3d target)
{
	return (vector3d_dot_double(base, dot_vector3d(target, base)));
}
