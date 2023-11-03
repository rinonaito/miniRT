/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:11:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 16:09:19 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "init.h"
#include "config.h"

//C -50.0,0,20 0,0,1 70
int	set_camera(t_scene *scene, const char *const line, bool *have_bump_texture)
{
	size_t	str_index;

	(void)have_bump_texture;
	if (get_num_of_token(line) != CAMERA_ARGS)
		return (EXIT_FAILURE);
	str_index = 0;
	if (set_str_in_vector3d(&scene->camera.origin, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_coordinate(scene->camera.origin)
		|| set_str_in_vector3d(&scene->camera.direction_vec, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_normalized_vector(scene->camera.direction_vec)
		|| set_str_in_double(&scene->camera.fov, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_fov(scene->camera.fov))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
