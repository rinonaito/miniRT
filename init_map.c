/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:12:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 20:30:57 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "init.h"
#include "object.h"
#include "vector.h"
#include <stdlib.h>
#include <math.h>

static void	init_sphere(t_scene *scene, int *index);
static void	init_cone(t_scene *scene, int *index);
static void	init_plane(t_scene *scene, int *index);
static void	init_cylinder(t_scene *scene, int *index);
static void	init_camera(t_scene *scene);
static void	init_ambient(t_scene *scene);
static void	init_lights(t_scene *scene);

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
	// init_cone(scene, &index);
	(void)init_cone;
	init_camera(scene);
	init_ambient(scene);
	init_lights(scene);
}

static void	init_sphere(t_scene *scene, int *index)
{
	t_sphere	*sphere = malloc(sizeof(t_sphere) * 1);
	sphere->center.x = 0.0;
	sphere->center.y = 0.0;
	sphere->center.z = 3.0;
	sphere->diameter = 2.0;
	sphere->color.red = 40;
	sphere->color.green = 53;
	sphere->color.blue = 158;
	sphere->color.red = 255;
	scene->objects[*index].object = sphere;
	scene->objects[*index].object_type = SPHERE_TYPE;
	scene->objects[*index].fp_hit_object = hit_sphere;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_sphere;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_sphere;
	scene->objects_num++;
	(*index)++;
//	t_sphere	*sphere2 = malloc(sizeof(t_sphere) * 1);
//	sphere2->center.x = -1.0;
//	sphere2->center.y = 1.0;
//	sphere2->center.z = 2.0;
//	sphere2->diameter = 1.0;
//	sphere2->color.red = 40;
//	sphere2->color.green = 53;
//	sphere2->color.blue = 158;
//	// sphere2->color.red = 0;
//	// sphere2->color.green = 0;
//	// sphere2->color.blue = 255;
//	scene->objects[*index].object = sphere2;
//	scene->objects[*index].object_type = SPHERE_TYPE;
//	scene->objects[*index].fp_hit_object = hit_sphere;
//	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_sphere;
//	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_sphere;
//	scene->objects_num++;
//	(*index)++;
}

static void	init_cone(t_scene *scene, int *index)
{
	t_cone	*cone = malloc(sizeof(t_cone) * 1);
	cone->top.x = 0.0;
	cone->top.y = 4.0;
	cone->top.z = 20.0;
	cone->height = 8.0;
	cone->direction_vec.x = -1.0;
	cone->direction_vec.y = -1.0;
	cone->direction_vec.z = -1.0;
	cone->direction_vec = normalize_vector3d(cone->direction_vec);
	cone->color.red = 40;
	cone->color.green = 53;
	cone->color.blue = 158;
	cone->phi = 15.0;
	scene->objects[*index].object = cone;
	scene->objects[*index].object_type = CONE_TYPE;
	scene->objects[*index].fp_hit_object = hit_cone;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_cone;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_cone;
	scene->objects_num++;

	t_circle *circle = malloc(sizeof(t_circle) * 1);
	circle->direction_vec = cone->direction_vec;
	circle->center.x = ((t_cone *)scene->objects[*index].object)->top.x
		+ circle->direction_vec.x
		* ((t_cone *)scene->objects[*index].object)->height;
	circle->center.y = ((t_cone *)scene->objects[*index].object)->top.y
		+ circle->direction_vec.y
		* ((t_cone *)scene->objects[*index].object)->height;
	circle->center.z = ((t_cone *)scene->objects[*index].object)->top.z
		+ circle->direction_vec.z
		* ((t_cone *)scene->objects[*index].object)->height;
	circle->diameter 
		= tan(((t_cone *)scene->objects[*index].object)->phi * M_PI / 180.0)
			* ((t_cone *)scene->objects[*index].object)->height * 2;
	circle->color = ((t_cone *)scene->objects[*index].object)->color;
	scene->objects[*index + 1].object = circle;
	scene->objects[*index + 1].object_type = CIRCLE_TYPE;
	scene->objects[*index + 1].fp_hit_object = hit_circle;
	scene->objects[*index + 1].fp_get_normal_vector_for_object = get_normal_vector_for_circle;
	scene->objects[*index + 1].fp_get_pixel_color_for_object = get_pixel_color_for_circle;
	scene->objects_num++;
	// printf("r = %lf, height = %lf\n", ((t_circle *)scene->objects[(*index) + 1].object)->diameter, ((t_cone *)scene->objects[*index].object)->height);
	(*index) += 2;
}

static void	init_plane(t_scene *scene, int *index)
{
	t_plane	*plane = malloc(sizeof(t_plane) * 1);
	plane->coordinate.x = 5.0;
	plane->coordinate.y = 1.0;
	plane->coordinate.z = 2.0;
	plane->direction_vec.x = 0.5;
	plane->direction_vec.y = 0.5;
	plane->direction_vec.z = 0.0;
	plane->color.red = 10;
	plane->color.green = 200;
	plane->color.blue = 50;
	plane->texture = CHECKER;
	scene->objects[*index].object = plane;
	scene->objects[*index].object_type = PLANE_TYPE;
	scene->objects[*index].fp_hit_object = hit_plane;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_plane;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_plane;
	scene->objects_num++;
	(*index)++;

	t_plane	*plane2 = malloc(sizeof(t_plane) * 1);
	plane2->coordinate.x = -5.0;
	plane2->coordinate.y = -1.0;
	plane2->coordinate.z = 15.0;
	plane2->direction_vec.x = -5.0;
	plane2->direction_vec.y = 0.0;
	plane2->direction_vec.z = 1.0;
	plane2->color.red = 200;
	plane2->color.green = 100;
	plane2->color.blue = 100;
	plane2->texture = CHECKER;
	scene->objects[*index].object = plane2;
	scene->objects[*index].object_type = PLANE_TYPE;
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
	tube->center.z = 10.0;
	tube->direction_vec.x = 0.0;
	tube->direction_vec.y = 1.0;
	tube->direction_vec.z = 0.0;
	tube->direction_vec = normalize_vector3d(tube->direction_vec);
	tube->diameter = 2.0;
	tube->height = 4.0;
	tube->color.red = 100;
	tube->color.green = 200;
	tube->color.blue = 100;
	scene->objects[*index].object = tube;
	scene->objects[*index].object_type = TUBE_TYPE;
	scene->objects[*index].fp_hit_object = hit_tube;
	scene->objects[*index].fp_get_normal_vector_for_object = get_normal_vector_for_tube;
	scene->objects[*index].fp_get_pixel_color_for_object = get_pixel_color_for_tube;
	scene->objects_num++;

	t_circle *circle_top = malloc(sizeof(t_circle) * 1);
	circle_top->center.x = ((t_tube *)scene->objects[*index].object)->center.x
		+ ((t_tube *)scene->objects[*index].object)->direction_vec.x
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_top->center.y = ((t_tube *)scene->objects[*index].object)->center.y
		+ ((t_tube *)scene->objects[*index].object)->direction_vec.y
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_top->center.z = ((t_tube *)scene->objects[*index].object)->center.z
		+ ((t_tube *)scene->objects[*index].object)->direction_vec.z
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_top->direction_vec = ((t_tube *)scene->objects[*index].object)->direction_vec;
	circle_top->diameter = ((t_tube *)scene->objects[*index].object)->diameter;
	circle_top->color = ((t_tube *)scene->objects[*index].object)->color;
	scene->objects[*index + 1].object = circle_top;
	scene->objects[*index + 1].object_type = CIRCLE_TYPE;
	scene->objects[*index + 1].fp_hit_object = hit_circle;
	scene->objects[*index + 1].fp_get_normal_vector_for_object = get_normal_vector_for_circle;
	scene->objects[*index + 1].fp_get_pixel_color_for_object = get_pixel_color_for_circle;
	scene->objects_num++;

	t_circle *circle_bottom = malloc(sizeof(t_circle) * 1);
	circle_bottom->center.x = ((t_tube *)scene->objects[*index].object)->center.x
		- ((t_tube *)scene->objects[*index].object)->direction_vec.x
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_bottom->center.y = ((t_tube *)scene->objects[*index].object)->center.y
		- ((t_tube *)scene->objects[*index].object)->direction_vec.y
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_bottom->center.z = ((t_tube *)scene->objects[*index].object)->center.z
		- ((t_tube *)scene->objects[*index].object)->direction_vec.z
		* ((t_tube *)scene->objects[*index].object)->height / 2;
	circle_bottom->direction_vec = ((t_tube *)scene->objects[*index].object)->direction_vec;
	circle_bottom->diameter = ((t_tube *)scene->objects[*index].object)->diameter;
	circle_bottom->color = ((t_tube *)scene->objects[*index].object)->color;
	scene->objects[*index + 2].object = circle_bottom;
	scene->objects[*index + 2].object_type = CIRCLE_TYPE;
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
	set_vector3d(&scene->camera.direction_vec, 0.0, 0.0, 1.0);
	scene->camera.direction_vec
		= normalize_vector3d(scene->camera.direction_vec);
}

static void init_ambient(t_scene *scene)
{
	scene->ambient.lighting_ratio = 0.3;
	scene->ambient.color.red = 255;
	scene->ambient.color.green = 255;
	scene->ambient.color.blue = 255;
}

static void	init_lights(t_scene *scene)
{
	scene->lights = malloc(sizeof(t_light) * 2);
	scene->lights[0].origin.x = 0.0;
	scene->lights[0].origin.y = 2.0;
	scene->lights[0].origin.z = 0.0;
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

//以下、is_invalid_lineのデバック関数
// #include <stdio.h>
// void	_print_identifier(t_scene *scene, t_identifier_type identifier_type)
// {
// 	if (identifier_type == A)
// 	{
// 		printf("ambient.color r = %d, g = %d, b = %d \n",
//		scene->ambient.color.red, scene->ambient.color.green,
//		scene->ambient.color.blue);
// 		printf("ambient.lighting_ratio = %lf\n", scene->ambient.lighting_ratio);
// 		printf("\n");
// 	}
// 	else if (identifier_type == C)
// 	{
// 		printf("camera.direction_vec x = %lf, y = %lf, z = %lf\n",
//		scene->camera.direction_vec.x, scene->camera.direction_vec.y,
//		scene->camera.direction_vec.z);
// 		printf("camera.fov = %lf\n", scene->camera.fov);
// 		printf("camera.origin x = %lf, y = %lf, z = %lf\n",
//		scene->camera.origin.x, scene->camera.origin.y,
//		scene->camera.origin.z);
// 		printf("\n");
// 	}
// 	else if (identifier_type == L)
// 	{
// 		printf("light.origin(x, y, z)= (%lf, %lf, %lf)\n",
// 			scene->lights[0].origin.x, scene->lights[0].origin.y, scene->lights[0].origin.z);	
// 		printf("light.color(r, g, b) = (%d, %d, %d)\n",
// 			scene->lights[0].color.red, scene->lights[0].color.green, scene->lights[0].color.blue);
// 		printf("\n");
// 	}
// 	else if (identifier_type == sp)
// 	{
// 		t_sphere *sphere = ((t_sphere *)scene->objects[0].object);
// 		printf("sphere.center x = %lf, y = %lf, z = %lf\n", sphere->center.x, sphere->center.y, sphere->center.z);
// 		printf("sphere.color r = %d, g = %d, b = %d\n", sphere->color.red, sphere->color.green, sphere->color.blue);
// 		printf("sphere.diameter = %lf\n", sphere->diameter);
// 		printf("\n");
// 	}
// 	else if (identifier_type == pl)
// 	{
// 		t_plane *plane = ((t_plane *)scene->objects[1].object);
// 		printf("plane->color r = %d, g = %d, b = %d\n", plane->color.red, plane->color.green, plane->color.blue);
// 		printf("plane->coordinate x = %lf, y = %lf, z = %lf\n", plane->coordinate.x, plane->coordinate.y, plane->coordinate.z);
// 		printf("plane->direction_vec x = %lf, y = %lf, z = %lf\n", plane->direction_vec.x, plane->direction_vec.y, plane->direction_vec.z);
// 		printf("\n");
// 	}
// 	else if (identifier_type == cy)
// 	{
// 		t_tube *tube = ((t_tube *)scene->objects[2].object);
// 		printf("tube.center(x, y, z) = (%lf, %lf, %lf)\n",
// 			tube->center.x, tube->center.y, tube->center.z);
// 		printf("tube.direction_vec(x, y, z) = (%lf, %lf, %lf)\n",
// 			tube->direction_vec.x, tube->direction_vec.y, tube->direction_vec.z);
// 		printf("tube.color(r, g, b) = (%d, %d, %d)\n",
// 			tube->color.red, tube->color.green, tube->color.blue);
// 		printf("tube.diameter = %lf\n", tube->diameter);
// 		printf("tube.height = %lf\n", tube->height);
// 		t_circle *top = ((t_circle *)scene->objects[3].object);
// 		printf("top.center(x, y, z) = (%lf, %lf, %lf)\n",
// 			top->center.x, top->center.y, top->center.z);
// 		printf("top.direction_vec(x, y, z) = (%lf, %lf, %lf)\n",
// 			top->direction_vec.x, top->direction_vec.y, top->direction_vec.z);
// 		printf("top.color(r, g, b) = (%d, %d, %d)\n",
// 			top->color.red, top->color.green, top->color.blue);
// 		printf("top.diameter = %lf\n", top->diameter);
// 		t_circle *bottom = ((t_circle *)scene->objects[4].object);
// 		printf("bottom.center(x, y, z) = (%lf, %lf, %lf)\n",
// 			bottom->center.x, bottom->center.y, bottom->center.z);
// 		printf("bottom.direction_vec(x, y, z) = (%lf, %lf, %lf)\n",
// 			bottom->direction_vec.x, bottom->direction_vec.y, bottom->direction_vec.z);
// 		printf("bottom.color(r, g, b) = (%d, %d, %d)\n",
// 			bottom->color.red, bottom->color.green, bottom->color.blue);
// 		printf("bottom.diameter = %lf\n", bottom->diameter);
// 		printf("\n");
// 	}
// 	else if (identifier_type == co)
// 	{
// 		t_cone *cone = ((t_cone *)scene->objects[5].object);
// 		printf("cone.top(x, y, z) = (%lf, %lf, %lf)\n",
// 			cone->top.x, cone->top.y, cone->top.z);
// 		printf("cone.phi = %lf\n", cone->phi);
// 		printf("cone.height = %lf\n", cone->height);
// 		printf("cone.direction_vec(x, y, z) = (%lf, %lf, %lf)\n",
// 			cone->direction_vec.x, cone->direction_vec.y, cone->direction_vec.z);
// 		printf("cone.color(r, g, b) = (%d, %d, %d)\n",
// 			cone->color.red, cone->color.green, cone->color.blue);
// 		t_circle	*circle = ((t_circle *)scene->objects[6].object);
// 		printf("circle.center(x, y, z) = (%lf, %lf, %lf)\n",
// 			circle->center.x, circle->center.y, circle->center.z);
// 		printf("circle.direction_vec(x, y, z) = (%lf, %lf, %lf)\n",
// 			circle->direction_vec.x, circle->direction_vec.y, circle->direction_vec.z);
// 		printf("circle.color(r, g, b) = (%d, %d, %d)\n",
// 			circle->color.red, circle->color.green, circle->color.blue);
// 		printf("\n");
// 	}
// }
