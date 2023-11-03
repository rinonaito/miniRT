/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_with_bump.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:24:31 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/03 13:06:41 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

t_vector3d	get_normal_vector_with_bump(
		t_vector2d hit_point,
		t_vector3d normal_vec,
		t_bumpmap bumpmap)
{
	t_vector3d	new_normal_vec;
	size_t		col;
	size_t		row;

	row = (int)(hit_point.x * bumpmap.map_height * 10) % bumpmap.map_height;
	col = (int)(hit_point.y * bumpmap.map_width * 10) % bumpmap.map_width;
	new_normal_vec = normalize_vector3d(
			addition_vector3d(normal_vec, bumpmap.map[row][col]));
	return (new_normal_vec);
}
