/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 14:46:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "error_utils.h"
#include "config.h"
#include "libft.h"
#include <stdbool.h>

// #include <stdio.h>
// void	_print_identifier(t_scene *scene, t_identifier_type identifier_type)
// {
// 	if (identifier_type == A)
// 	{
// 		printf("ambient.color r = %d, g = %d, b = %d \n", scene->ambient.color.red, scene->ambient.color.green, scene->ambient.color.blue);
// 		printf("ambient.lighting_ratio = %lf\n", scene->ambient.lighting_ratio);
// 		printf("\n");
// 	}
// 	else if (identifier_type == C)
// 	{
// 		printf("camera.direction_vec x = %lf, y = %lf, z = %lf\n", scene->camera.direction_vec.x, scene->camera.direction_vec.y, scene->camera.direction_vec.z);
// 		printf("camera.fov = %lf\n", scene->camera.fov);
// 		printf("camera.origin x = %lf, y = %lf, z = %lf\n", scene->camera.origin.x, scene->camera.origin.y, scene->camera.origin.z);
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

/**
 * lineにNULLが来ることはない
*/
bool	is_invalid_line(
	const char *const line,
	const t_parser *parser,
	t_scene *scene)
{
	t_identifier_type	identifier_type;
	size_t				index;

	if (ft_strlen(line) == 0)
		return (false);
	index = 0;
	identifier_type = get_identifier_type(line, &index, parser);
	if (identifier_type == UNDEFINED)
	{
		print_error_msg(INVALID_IDENTIFIER);
		return (true);
	}
	//1行の識別子情報までわかっている。
	// if (parser[identifier_type].fp_is_invalid_identifier(line, scene, index))
	// 	return (true);
	parser[identifier_type].fp_set_identifier(scene, line);
	return (false);
}
