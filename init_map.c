/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:12:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/30 13:56:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include <stdlib.h>

void	init_map(t_scene *scene)
{
	set_vector3d(&scene->camera.origin, 0.0, 0.0, 0.0);
	scene->camera.fov = 90;
	set_vector3d(&scene->camera.direction_vec, -50.0, 0.0, 20.0);
	scene->ambient.lighting_ratio = 1.0;
	scene->spheres = malloc(sizeof(t_sphere) * 2);
	scene->spheres[0].center.x = 0.5;
	scene->spheres[0].center.y = 0.0;
	scene->spheres[0].center.z = 10.6;
	scene->spheres[0].diameter = 12.6;
	scene->spheres[0].color.red = 0;
	scene->spheres[0].color.green = 200;
	scene->spheres[0].color.blue = 0;
	scene->spheres[1].center.x = 10.5;
	scene->spheres[1].center.y = 5.5;
	scene->spheres[1].center.z = 10.6;
	scene->spheres[1].diameter = 5.6;
	scene->spheres[1].color.red = 0;
	scene->spheres[1].color.green = 100;
	scene->spheres[1].color.blue = 10;
	scene->spheres_num = 2;
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
