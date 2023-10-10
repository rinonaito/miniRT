/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:12:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 21:36:45 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include "object.h"
#include "vector.h"
#include <stdlib.h>

static void	init_sphere(t_scene *scene, int *index);
static void	init_plane(t_scene *scene, int *index);
static void	init_cylinder(t_scene *scene, int *index);
static void	init_camera(t_scene *scene);
static void	init_lighs(t_scene *scene);

#include <stdio.h>
void	init_map(t_scene *scene)
{
	int index = 0;
	scene->objects = malloc(sizeof(t_object) * 100);
	scene->objects_num = 0;
	init_sphere(scene, &index);
	(void)init_sphere;
	init_plane(scene, &index);
	(void)init_plane;
	//init_cylinder(scene, &index);
	(void)init_cylinder;
	init_camera(scene);
	init_lighs(scene);
}

static void	init_sphere(t_scene *scene, int *index)
{
	t_sphere	*sphere = malloc(sizeof(t_sphere) * 1);
	sphere->center.x = 0.0;
	sphere->center.y = 0.0;
	sphere->center.z = 10.6;
	sphere->diameter = 3.8;
	sphere->color.red = 40;
	sphere->color.green = 53;
	sphere->color.blue = 158;
	scene->objects[*index].object = sphere;
	scene->objects[*index].object_type = SPHERE;
	scene->objects[*index].fp_hit_object = hit_sphere;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_sphere;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_sphere;
	scene->objects_num++;
	(*index)++;
}

static void	init_plane(t_scene *scene, int *index)
{
	t_plane	*plane = malloc(sizeof(t_plane) * 1);
	plane->coordinate.x = 5.0;
	plane->coordinate.y = -5.0;
	plane->coordinate.z = 2.0;
	plane->direction_vec.x = 0.0;
	plane->direction_vec.y = 1.0;
	plane->direction_vec.z = 0.0;
	plane->color.red = 255;
	plane->color.green = 255;
	plane->color.blue = 255;
	scene->objects[*index].object = plane;
	scene->objects[*index].object_type = PLANE;
	scene->objects[*index].fp_hit_object = hit_plane;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_plane;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_plane;
	scene->objects_num++;
	(*index)++;
}

static void	init_cylinder(t_scene *scene, int *index)
{
	t_tube *tube = malloc(sizeof(t_tube) * 1);
	tube->center.x = 0.0;
	tube->center.y = 0.0;
	tube->center.z = 10.6;
	tube->direction_vec.x = 3.0;
	tube->direction_vec.y = 3.0;
	tube->direction_vec.z = -3.0;
	tube->diameter = 3.6;
	tube->height = 5.8;
	tube->color.red = 0;
	tube->color.green = 255;
	tube->color.blue = 0;
	scene->objects[*index].object = tube;
	scene->objects[*index].object_type = TUBE;
	scene->objects[*index].fp_hit_object = hit_tube;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_tube;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_tube;
	scene->objects_num++;

	t_vector3d vector = normalize_vector3d(((t_tube *)scene->objects[*index].object)->direction_vec);
	t_circle *circle_top = malloc(sizeof(t_circle) * 1);
	circle_top->center.x = ((t_tube *)scene->objects[*index].object)->center.x
		+ vector.x
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_top->center.y = ((t_tube *)scene->objects[*index].object)->center.y
		+ vector.y
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_top->center.z = ((t_tube *)scene->objects[*index].object)->center.z
		+ vector.z
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_top->direction_vec = vector;
	circle_top->diameter = ((t_tube *)scene->objects[*index].object)->diameter;
	circle_top->color = ((t_tube *)scene->objects[*index].object)->color;
	scene->objects[*index + 1].object = circle_top;
	scene->objects[*index + 1].object_type = CIRCLE;
	scene->objects[*index + 1].fp_hit_object = hit_circle;
	scene->objects[*index + 1].fp_get_normal_vector_for_object = get_normal_vector_for_circle;
	scene->objects[*index + 1].fp_get_pixel_color_for_object = get_pixel_color_for_circle;
	scene->objects_num++;

	t_circle *circle_bottom = malloc(sizeof(t_circle) * 1);
	circle_bottom->center.x = ((t_tube *)scene->objects[*index].object)->center.x
		- vector.x
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_bottom->center.y = ((t_tube *)scene->objects[*index].object)->center.y
		- vector.y
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_bottom->center.z = ((t_tube *)scene->objects[*index].object)->center.z
		- vector.z
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_bottom->direction_vec = vector;
	circle_bottom->diameter = ((t_tube *)scene->objects[*index].object)->diameter;
	circle_bottom->color = ((t_tube *)scene->objects[*index].object)->color;
	scene->objects[*index + 2].object = circle_bottom;
	scene->objects[*index + 2].object_type = CIRCLE;
	scene->objects[*index + 2].fp_hit_object = hit_circle;
	scene->objects[*index + 2].fp_get_normal_vector_for_object = get_normal_vector_for_circle;
	scene->objects[*index + 2].fp_get_pixel_color_for_object = get_pixel_color_for_circle;
	scene->objects_num++;
	// printf("tube (x[%lf], y[%lf]. z[%lf]), \ntop (x[%lf], y[%lf]. z[%lf]), \nbottom (x[%lf], y[%lf]. z[%lf])\n",
	// 	((t_tube *)scene->objects[*index].object)->center.x, ((t_tube *)scene->objects[*index].object)->center.y, ((t_tube *)scene->objects[*index].object)->center.z,
	// 	((t_tube *)scene->objects[*index + 1].object)->center.x, ((t_tube *)scene->objects[*index + 1].object)->center.y, ((t_tube *)scene->objects[*index + 1].object)->center.z,
	// 	((t_tube *)scene->objects[*index + 2].object)->center.x, ((t_tube *)scene->objects[*index + 2].object)->center.y, ((t_tube *)scene->objects[*index + 2].object)->center.z);
	*index += 3;
}

static void	init_camera(t_scene *scene)
{
	set_vector3d(&scene->camera.origin, 0.0, 0.0, 0.0);
	scene->camera.fov = 90;
	set_vector3d(&scene->camera.direction_vec, 0.0, 0.0, 20.0);
	scene->camera.direction_vec
		= normalize_vector3d(scene->camera.direction_vec);
	scene->ambient.lighting_ratio = 0.3;
}

static void	init_lighs(t_scene *scene)
{
	scene->lights = malloc(sizeof(t_light) * 2);
	scene->lights[0].origin.x = 10;
	scene->lights[0].origin.y = 10;
	scene->lights[0].origin.z = -10.6;
	scene->lights[0].lighting_ratio = 1.0;
	scene->lights[0].color.blue = 255;
	scene->lights[0].color.green = 255;
	scene->lights[0].color.red = 255;
	scene->lights[1].origin.x = -20;
	scene->lights[1].origin.y = -20;
	scene->lights[1].origin.z = 0;
	scene->lights[1].lighting_ratio = 1.0;
	scene->lights[1].color.blue = 0;
	scene->lights[1].color.green = 255;
	scene->lights[1].color.red = 0;
	scene->lights_num = 1;
}
