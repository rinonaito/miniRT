/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:46:02 by yshimoma         ###   ########.fr       */
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
	char	*word;
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
	word = get_first_word_by_space(line, &str_index);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_vector3d(&scene->lights[i].origin, word);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_string_to_double(&scene->lights[i].lighting_ratio, word, 1.0);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_rgb(&scene->lights[i].color, word);
	free(word);
	if (scene->lights_num != 0)
		free(backup);
	scene->lights_num++;
}
