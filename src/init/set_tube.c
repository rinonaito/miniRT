/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:51:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:47:17 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "object.h"
#include "parser.h"
#include "vector.h"
#include "init.h"
#include "x_wrapper.h"
#include <stdlib.h>

//cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
int	set_tube(t_scene *scene, const char *const line)
{
	t_tube	*tube;
	size_t	str_index;

	tube = ft_xcalloc(1, sizeof(t_tube));
	resize_objects_array(&scene->objects, scene->objects_num);
	str_index = 0;
	if (set_str_in_vector3d(&tube->center, line, &str_index) == EXIT_FAILURE
		|| is_invalid_coordinate(tube->center)
		|| set_str_in_vector3d(&tube->direction_vec, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_normalized_vector(tube->direction_vec)
		|| set_str_in_double(&tube->diameter, line, &str_index) == EXIT_FAILURE
		|| is_invalid_double(tube->diameter, MAX_DIAMETER, MIN_DIAMETER)
		|| set_str_in_double(&tube->height, line, &str_index) == EXIT_FAILURE
		|| is_invalid_double(tube->height, MAX_HEIGHT, MIN_HEIGHT)
		|| set_str_in_rgb(&tube->color, line, &str_index) == EXIT_FAILURE
		|| is_invalid_rgb(tube->color))
		return (EXIT_FAILURE);
	scene->objects[scene->objects_num] = create_object(
			(void *)tube,
			hit_tube,
			get_normal_vector_for_tube,
			get_pixel_color_for_tube);
	scene->objects_num++;
	return (EXIT_SUCCESS);
}
