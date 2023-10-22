/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:51:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:50:49 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"
#include "parser.h"
#include "vector.h"
#include "init.h"
#include "x_wrapper.h"
#include <stdlib.h>

//cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
void	set_tube(t_scene *scene, const char *const line)
{
	t_tube	*tube;
	size_t	str_index;
	char	*word;

	tube = ft_xcalloc(1, sizeof(t_tube));
	resize_objects_array(scene->objects, scene->objects_num);
	str_index = 0;
	word = get_first_word_by_space(line, &str_index);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_vector3d(&tube->center, word);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_vector3d(&tube->direction_vec, word);
	tube->direction_vec = normalize_vector3d(tube->direction_vec);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_string_to_double(&tube->diameter, word, 300.0);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_string_to_double(&tube->height, word, 300.0);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_rgb(&tube->color, word);
	free(word);
	scene->objects[scene->objects_num] = create_object(
			(void *)tube,
			hit_tube,
			get_normal_vector_for_tube,
			get_pixel_color_for_tube);
	scene->objects_num++;
}
