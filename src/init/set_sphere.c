/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:13:04 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:14:08 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "x_wrapper.h"
#include "parser.h"
#include "init.h"
#include "object.h"
#include "config.h"
#include <stdlib.h>

//sp 0.0,0.0,20.6 12.6 10,0,255
int	set_sphere(
	t_scene *scene,
	const char *const line,
	bool *have_bump_texture)
{
	t_sphere	*sphere;
	size_t		str_index;

	(void)have_bump_texture;
	if (get_num_of_token(line) != SPHERE_ARGS)
		return (EXIT_FAILURE);
	sphere = ft_xcalloc(1, sizeof(t_sphere));
	resize_objects_array(&scene->objects, scene->objects_num);
	str_index = 0;
	if (set_str_in_vector3d(&sphere->center, line, &str_index) == EXIT_FAILURE
		|| is_invalid_coordinate(sphere->center)
		|| set_str_in_double(&sphere->diameter, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_double(
			sphere->diameter, MAX_DIAMETER, MIN_DIAMETER)
		|| set_str_in_rgb(&sphere->color, line, &str_index) == EXIT_FAILURE
		|| is_invalid_rgb(sphere->color))
		return (EXIT_FAILURE);
	scene->objects[scene->objects_num] = create_object(
			(void *)sphere, hit_sphere,
			get_normal_vector_for_sphere,
			get_pixel_color_for_sphere);
	scene->objects_num++;
	return (EXIT_SUCCESS);
}
