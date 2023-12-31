/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 16:08:36 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "object.h"
#include "types.h"
#include "init.h"
#include "object.h"
#include "config.h"

static void	_set_circle(
	t_scene *scene,
	const t_tube tube,
	const double tube_height)
{
	t_vector3d	circle_center;
	t_circle	*circle;

	resize_objects_array(&scene->objects, scene->objects_num);
	circle_center = get_circle_center(
			tube.center, tube.direction_vec, tube_height);
	circle = set_circle(circle_center, tube.diameter,
			tube.direction_vec, tube.color);
	scene->objects[scene->objects_num] = create_object(
			(void *)circle, hit_circle, get_normal_vector_for_circle,
			get_pixel_color_for_circle);
	scene->objects_num++;
}

//cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
int	set_cylinder(
	t_scene *scene,
	const char *const line,
	bool *have_bump_texture)
{
	t_tube		*tube;

	(void)have_bump_texture;
	if (get_num_of_token(line) != CYLINDER_ARGS
		|| set_tube(scene, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	tube = (t_tube *)scene->objects[scene->objects_num - 1].object;
	_set_circle(scene, *tube, tube->height / 2);
	_set_circle(scene, *tube, tube->height / 2 * -1);
	return (EXIT_SUCCESS);
}
