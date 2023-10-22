/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:38:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:35:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "init.h"
#include "object.h"
#include <math.h>

void	set_cone(t_scene *scene, const char *const line)
{
	t_vector3d	circle_center;
	double		diameter;

	set_cone_side(scene, line);
	circle_center
		= get_circle_center(((t_cone *)scene->objects[scene->objects_num - 1].object)->top,
			((t_cone *)scene->objects[scene->objects_num - 1].object)->direction_vec,
			((t_cone *)scene->objects[scene->objects_num - 1].object)->height);
	diameter
		= tan(((t_cone *)scene->objects[scene->objects_num - 1].object)
			->phi * M_PI / 180.0)
		* ((t_cone *)scene->objects[scene->objects_num - 1].object)->height * 2;
	set_circle(circle_center,
		diameter,
		((t_cone *)scene->objects[scene->objects_num - 1].object)->direction_vec,
		((t_cone *)scene->objects[scene->objects_num - 1].object)->color);
}
