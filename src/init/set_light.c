/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 19:24:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "x_wrapper.h"
#include "parser.h"
#include "config.h"
#include <stdlib.h>

void	_resize_lights_array(t_light **lights, const size_t lights_num)
{
	t_light	*backup;
	size_t	i;

	backup = *lights;
	*lights = ft_xcalloc(lights_num + 1, sizeof(t_light));
	i = 0;
	while (i < lights_num)
	{
		(*lights)[i] = backup[i];
		i++;
	}
	if (lights_num != 0)
		free(backup);
}

//L -40.0,50.0,0.0 0.6 10,0,255
int	set_light(t_scene *scene, const char *const line)
{
	size_t	str_index;
	t_light	*light;

	if (get_num_of_token(line) != LIGHT_ARGS + BONUS_ARGS)
		return (EXIT_FAILURE);
	_resize_lights_array(&scene->lights, scene->lights_num);
	str_index = 0;
	light = &scene->lights[scene->lights_num];
	if (set_str_in_vector3d(&light->origin, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_coordinate(light->origin)
		|| set_str_in_double(&light->lighting_ratio, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_lighting_ratio(light->lighting_ratio)
		|| set_str_in_rgb(&light->color, line, &str_index) == EXIT_FAILURE
		|| is_invalid_rgb(light->color))
	{
		return (EXIT_FAILURE);
	}
	scene->lights_num++;
	return (EXIT_SUCCESS);
}
