/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:00:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 20:00:55 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "x_wrapper.h"
#include "init.h"
#include "vector.h"
#include "object.h"

void	set_cone_side(t_scene *scene, const char *const line)
{
	t_cone	*cone;
	size_t	str_index;

	cone = ft_xcalloc(1, sizeof(t_cone));
	resize_objects_array(&scene->objects, scene->objects_num);
	str_index = 0;
	skip_identifier(line, &str_index);
	set_str_in_vector3d(&cone->top, line, &str_index);
	set_str_in_vector3d(&cone->direction_vec, line, &str_index);
	cone->direction_vec = normalize_vector3d(cone->direction_vec);
	set_str_in_double(&cone->phi, line, &str_index);
	set_str_in_double(&cone->height, line, &str_index);
	set_str_in_rgb(&cone->color, line, &str_index);
	scene->objects[scene->objects_num] = create_object(
			(void *)cone,
			hit_cone,
			get_normal_vector_for_cone,
			get_pixel_color_for_cone);
	scene->objects_num++;
}
