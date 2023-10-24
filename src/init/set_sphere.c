/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:13:04 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/24 21:17:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "x_wrapper.h"
#include "parser.h"
#include "init.h"
#include "object.h"
#include <stdlib.h>

//sp 0.0,0.0,20.6 12.6 10,0,255
void	set_sphere(t_scene *scene, const char *const line)
{
	t_sphere	*sphere;
	size_t		str_index;

	sphere = ft_xcalloc(1, sizeof(t_sphere));
	resize_objects_array(&scene->objects, scene->objects_num);
	str_index = 0;
	set_str_in_vector3d(&sphere->center, line, &str_index);
	set_str_in_double(&sphere->diameter, line, &str_index);
	set_str_in_rgb(&sphere->color, line, &str_index);
	scene->objects[scene->objects_num] = create_object(
			(void *)sphere,
			hit_sphere,
			get_normal_vector_for_sphere,
			get_pixel_color_for_sphere);
	scene->objects_num++;
}
