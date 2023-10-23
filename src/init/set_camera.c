/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:11:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 19:58:11 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "init.h"

//C -50.0,0,20 0,0,1 70
void	set_camera(t_scene *scene, const char *const line)
{
	size_t	str_index;

	str_index = 0;
	skip_identifier(line, &str_index);
	set_str_in_vector3d(&scene->camera.origin, line, &str_index);
	set_str_in_vector3d(&scene->camera.direction_vec, line, &str_index);
	set_str_in_double(&scene->camera.fov, line, &str_index);
}
