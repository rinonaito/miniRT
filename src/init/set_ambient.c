/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:11:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 16:08:21 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include "config.h"

//A 0.2 255,255,255
//TODO
//	引数の数チェックが終わっていない
int	set_ambient(t_scene *scene, const char *const line, bool *have_bump_texture)
{
	size_t	str_index;

	(void)have_bump_texture;
	if (get_num_of_token(line) != AMBIENT_ARGS)
		return (EXIT_FAILURE);
	str_index = 0;
	if (set_str_in_double(&scene->ambient.lighting_ratio, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_lighting_ratio(scene->ambient.lighting_ratio)
		|| set_str_in_rgb(&scene->ambient.color, line, &str_index)
		== EXIT_FAILURE
		|| is_invalid_rgb(scene->ambient.color))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
