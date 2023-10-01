/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:12:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/01 12:11:35 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include <stdlib.h>

void	init_map(t_scene *scene)
{
	t_sphere *sphere;
	t_sphere *sphere2;

	set_vector3d(&scene->camera.origin, 0.0, 0.0, 0.0);
	scene->camera.fov = 90;
	set_vector3d(&scene->camera.direction_vec, -50.0, 0.0, 20.0);
	scene->ambient.lighting_ratio = 0.5;
	scene->objects = malloc(sizeof(t_object) * 2);
	sphere = malloc(sizeof(t_sphere) * 1);
	sphere->center.x = 0.5;
	sphere->center.y = 0.0;
	sphere->center.z = 10.6;
	sphere->diameter = 12.6;
	sphere->color.red = 0;
	sphere->color.green = 200;
	sphere->color.blue = 0;
	scene->objects[0].object = sphere;
	scene->objects[0].object_type = SPHERE;

	sphere2 = malloc(sizeof(t_sphere) * 1);
	sphere2->center.x = 5.5;
	sphere2->center.y = 5.5;
	sphere2->center.z = 10.6;
	sphere2->diameter = 5.6;
	sphere2->color.red = 0;
	sphere2->color.green = 200;
	sphere2->color.blue = 0;
	scene->objects[1].object = sphere2;
	scene->objects[1].object_type = SPHERE;
	scene->objects_num = 2;

	scene->lights = malloc(sizeof(t_light) * 2);
	scene->lights[0].origin.x = 1;
	scene->lights[0].origin.y = -1;
	scene->lights[0].origin.z = -1;
	scene->lights[0].lighting_ratio = 1;
	scene->lights[1].origin.x = -1;
	scene->lights[1].origin.y = 0;
	scene->lights[1].origin.z = -1;
	scene->lights[1].lighting_ratio = 1;
	scene->lights_num = 2;
}
