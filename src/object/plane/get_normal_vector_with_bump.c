/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_with_bump.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:24:31 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/03 12:28:42 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

// t_vector3d	get_normal_vector_with_bump(
// 		t_vector2d hit_point,
// 		t_vector3d normal_vec,
// 		t_bumpmap bumpmap)
// {
// 	t_vector3d	new_normal_vec;
// 	size_t		col;
// 	size_t		row;

// 	// new_normal_vec = normalize_vector3d(
// 	// 	addition_vector3d(normal_vec, ))
	// row = (int)hit_point.x % bumpmap.map_height;
	// col = (int)hit_point.y % bumpmap.map_width;
// 	printf("(row, col) = (%zu, %zu)\n", row, col);
// 	new_normal_vec
// 		= normalize_vector3d(
// 			addition_vector3d(bumpmap.map[row][col], normal_vec));
// 	return (new_normal_vec);
// }

t_vector3d	get_normal_vector_with_bump(
		t_vector2d hit_point,
		t_vector3d normal_vec,
		t_bumpmap bumpmap)
{
	t_vector3d	new_normal_vec;
	size_t		col;
	size_t		row;

	// printf("hit_point(x, y)=(%lf, %lf)\n", hit_point.x, hit_point.y);
	row = (int)(hit_point.x * bumpmap.map_height * 10) % bumpmap.map_height;
	col = (int)(hit_point.y * bumpmap.map_width * 10) % bumpmap.map_width;

	new_normal_vec = normalize_vector3d(addition_vector3d(normal_vec, bumpmap.map[row][col]));

	return (new_normal_vec);
}

// t_vector3d get_normal_vector_with_bump(
// 	t_vector2d hit_point,
// 	t_vector3d normal_vec,
// 	t_bumpmap bumpmap)
// {
// 	double scale = 0.1; // Adjust this value to get the desired bump effect
// 	int x = (int)(hit_point.x * bumpmap.map_width * 10);
// 	int y = (int)(hit_point.y * bumpmap.map_height * 10);

// 	// Ensure x and y are within the bounds of the bump map
// 	x = x % bumpmap.map_width;
// 	y = y % bumpmap.map_height;

// 	// Get the height value from the bump map
// 	double height = bumpmap.map[y][x].x; // assuming grayscale, so R=G=B

// 	// Compute the normal perturbation with respect to the height
// 	t_vector3d perturbation;
// 	perturbation.x = scale * (bumpmap.map[y][(x+1)%bumpmap.map_width].x - height);
// 	perturbation.y = scale * (bumpmap.map[(y+1)%bumpmap.map_height][x].x - height);
// 	perturbation.z = scale; 

// 	// Adjust the original normal with the perturbation
// 	t_vector3d new_normal = normalize_vector3d(addition_vector3d(normal_vec, perturbation));

// 	return new_normal;
// }
