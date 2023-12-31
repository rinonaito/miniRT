/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:53 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:14:39 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include "init.h"
#include "x_wrapper.h"
#include "object.h"
#include "config.h"

static int	_set_str_in_texture(
	t_texture_type *texture,
	const char *line,
	size_t *str_index)
{
	double	type;

	if (set_str_in_double(&type, line, str_index)
		|| is_invalid_double(type, BUMP, NORMAL))
		return (EXIT_FAILURE);
	if (NORMAL == (int)type)
		*texture = NORMAL;
	else if (CHECKER == (int)type)
		*texture = CHECKER;
	else if (BUMP == (int)type)
		*texture = BUMP;
	return (EXIT_SUCCESS);
}

static int	_set_plane_utils(
	t_plane *plane,
	const char *const line,
	const size_t num_of_token)
{
	size_t	str_index;

	str_index = 0;
	if (set_str_in_vector3d(&plane->coordinate, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_coordinate(plane->coordinate)
		|| set_str_in_vector3d(&plane->direction_vec, line, &str_index)
		|| is_invalid_normalized_vector(plane->direction_vec)
		== EXIT_FAILURE
		|| set_str_in_rgb(&plane->color, line, &str_index) == EXIT_FAILURE
		|| is_invalid_rgb(plane->color))
	{
		return (EXIT_FAILURE);
	}
	if (num_of_token == PLANE_ARGS + BONUS_ARGS)
	{
		if (_set_str_in_texture(&plane->texture, line, &str_index))
			return (EXIT_FAILURE);
	}
	else
		plane->texture = NORMAL;
	set_vector3d(&plane->basis_vec1, 0, 0, 0);
	set_vector3d(&plane->basis_vec2, 0, 0, 0);
	return (EXIT_SUCCESS);
}

//pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
int	set_plane(
	t_scene *scene,
	const char *const line,
	bool *have_bump_texture)
{
	t_plane			*plane;
	const size_t	num_of_token = get_num_of_token(line);

	if (num_of_token != PLANE_ARGS && num_of_token != PLANE_ARGS + BONUS_ARGS)
		return (EXIT_FAILURE);
	plane = ft_xcalloc(1, sizeof(t_plane));
	resize_objects_array(&scene->objects, scene->objects_num);
	if (_set_plane_utils(plane, line, num_of_token) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (plane->texture == BUMP)
		*have_bump_texture = true;
	scene->objects[scene->objects_num] = create_object(
			(void *)plane,
			hit_plane,
			get_normal_vector_for_plane,
			get_pixel_color_for_plane);
	scene->objects_num++;
	return (EXIT_SUCCESS);
}
