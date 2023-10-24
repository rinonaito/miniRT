/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:53 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/24 21:17:48 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include "init.h"
#include "x_wrapper.h"
#include "object.h"

//pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
void	set_plane(t_scene *scene, const char *const line)
{
	t_plane	*plane;
	size_t	str_index;

	plane = ft_xcalloc(1, sizeof(t_plane));
	resize_objects_array(&scene->objects, scene->objects_num);
	str_index = 0;
	set_str_in_vector3d(&plane->coordinate, line, &str_index);
	set_str_in_vector3d(&plane->direction_vec, line, &str_index);
	set_str_in_rgb(&plane->color, line, &str_index);
	scene->objects[scene->objects_num] = create_object(
			(void *)plane,
			hit_plane,
			get_normal_vector_for_plane,
			get_pixel_color_for_plane);
	scene->objects_num++;
}
