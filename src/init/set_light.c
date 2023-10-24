/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/24 21:17:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "x_wrapper.h"
#include "parser.h"
#include <stdlib.h>

//L -40.0,50.0,0.0 0.6 10,0,255
void	set_light(t_scene *scene, const char *const line)
{
	size_t	str_index;
	size_t	i;
	t_light	*backup;

	backup = scene->lights;
	scene->lights = ft_xcalloc(scene->lights_num + 1, sizeof(t_light));
	i = 0;
	while (i < scene->lights_num)
	{
		scene->lights[i] = backup[i];
		i++;
	}
	str_index = 0;
	set_str_in_vector3d(&scene->lights[i].origin, line, &str_index);
	set_str_in_double(&scene->lights[i].lighting_ratio, line, &str_index);
	set_str_in_rgb(&scene->lights[i].color, line, &str_index);
	if (scene->lights_num != 0)
		free(backup);
	scene->lights_num++;
}
