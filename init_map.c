/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:12:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/01 20:44:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include <stdlib.h>

void	init_map(t_scene *scene)
{
	t_sphere *sphere;
	t_sphere *sphere2;
	t_sphere *sphere3;

	set_vector3d(&scene->camera.origin, 0.0, 0.0, 0.0);
	scene->camera.fov = 90;
	set_vector3d(&scene->camera.direction_vec, 0.0, 0.0, 20.0);
	scene->ambient.lighting_ratio = 0.5;
	scene->objects = malloc(sizeof(t_object) * 3);
	sphere = malloc(sizeof(t_sphere) * 1);
	sphere->center.x = 0.0;
	sphere->center.y = 0.0;
	sphere->center.z = 10.6;
	sphere->diameter = 12.6;
	sphere->color.red = 40;
	sphere->color.green = 53;
	sphere->color.blue = 158;
	scene->objects[0].object = sphere;
	scene->objects[0].object_type = SPHERE;

	sphere2 = malloc(sizeof(t_sphere) * 1);
	sphere2->center.x = 5.5;
	sphere2->center.y = 5.5;
	sphere2->center.z = 10.6;
	sphere2->diameter = 5.6;
	sphere2->color.red = 24;
	sphere2->color.green = 18;
	sphere2->color.blue = 23;
	scene->objects[1].object = sphere2;
	scene->objects[1].object_type = SPHERE;

	sphere3 = malloc(sizeof(t_sphere) * 1);
	sphere3->center.x = -10.5;
	sphere3->center.y = 5.5;
	sphere3->center.z = 10.6;
	sphere3->diameter = 5.6;
	sphere3->color.red = 100;
	sphere3->color.green = 18;
	sphere3->color.blue = 23;
	scene->objects[2].object = sphere3;
	scene->objects[2].object_type = SPHERE;
	scene->objects_num = 3;

	scene->lights = malloc(sizeof(t_light) * 2);
	scene->lights[0].origin.x = 0;
	scene->lights[0].origin.y = 0;
	scene->lights[0].origin.z = 20;
	scene->lights[0].lighting_ratio = 1.0;
	scene->lights[0].color.blue = 0;
	scene->lights[0].color.green = 0;
	scene->lights[0].color.red = 255;
	scene->lights[1].origin.x = -1;
	scene->lights[1].origin.y = 0;
	scene->lights[1].origin.z = -1;
	scene->lights[1].lighting_ratio = 1.0;
	scene->lights[1].color.blue = 0;
	scene->lights[1].color.green = 255;
	scene->lights[1].color.red = 0;
	scene->lights_num = 2;
}
