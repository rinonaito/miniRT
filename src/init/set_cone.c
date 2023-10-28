/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:38:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 20:30:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "init.h"
#include "object.h"
#include "config.h"
#include <math.h>

int	set_cone(t_scene *scene, const char *const line)
{
	t_cone		*cone;
	t_vector3d	circle_center;
	double		diameter;
	t_circle	*circle;

	if (get_num_of_token(line) != CONE_ARGS
		|| set_cone_side(scene, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cone = ((t_cone *)scene->objects[scene->objects_num - 1].object);
	resize_objects_array(&scene->objects, scene->objects_num);
	circle_center
		= get_circle_center(cone->top,
			cone->direction_vec,
			cone->height);
	diameter
		= tan(cone->phi * M_PI / 180.0) * cone->height * 2;
	circle = set_circle(circle_center,
			diameter, cone->direction_vec, cone->color);
	scene->objects[scene->objects_num] = create_object(
			(void *)circle,
			hit_circle,
			get_normal_vector_for_circle,
			get_pixel_color_for_circle);
	scene->objects_num++;
	return (EXIT_SUCCESS);
}
