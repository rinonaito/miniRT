/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/04 12:43:40 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "x_wrapper.h"
#include "parser.h"
#include "config.h"
#include <stdlib.h>

//L -40.0,50.0,0.0 0.6 10,0,255
int	set_light(t_scene *scene, const char *const line)
{
	size_t	str_index;
	t_light	*light;

	if (get_num_of_token(line) != LIGHT_ARGS)
		return (EXIT_FAILURE);
	str_index = 0;
	light = &scene->light;
	if (set_str_in_vector3d(&light->origin, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_coordinate(light->origin)
		|| set_str_in_double(&light->lighting_ratio, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_lighting_ratio(light->lighting_ratio))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
