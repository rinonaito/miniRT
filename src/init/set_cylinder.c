/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 12:51:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "object.h"
#include "types.h"
#include "init.h"
#include "object.h"

//cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
void	set_cylinder(t_scene *scene, const char *const line)
{
	t_tube		*tube;
	t_vector3d	circle_center;
	t_circle 	*top;
	t_circle	*bottom;

	set_tube(scene, line);
	tube = (t_tube *)scene->objects[scene->objects_num - 1].object; 
	resize_objects_array(&scene->objects, scene->objects_num);
	circle_center = get_circle_center(tube->center, tube->direction_vec, tube->height / 2);
	top = set_circle(circle_center, tube->diameter, tube->direction_vec, tube->color);
	scene->objects[scene->objects_num] = create_object(
		(void *)top,
		hit_circle,
		get_normal_vector_for_circle,
		get_pixel_color_for_circle);
	scene->objects_num++;
	resize_objects_array(&scene->objects, scene->objects_num);
	circle_center = get_circle_center(tube->center, tube->direction_vec, tube->height / 2 * -1);
	bottom = set_circle(circle_center, tube->diameter, tube->direction_vec, tube->color);
	scene->objects[scene->objects_num] = create_object(
		(void *)bottom,
		hit_circle,
		get_normal_vector_for_circle,
		get_pixel_color_for_circle);
	scene->objects_num++;
}
