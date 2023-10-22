/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:00:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:40:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "x_wrapper.h"
#include "init.h"
#include "vector.h"
#include "object.h"

void	set_cone_side(t_scene *scene, const char *const line)
{
	t_cone	*cone;
	size_t	str_index;
	char	*word;

	cone = ft_xcalloc(1, sizeof(t_cone));
	resize_objects_array(scene->objects, scene->objects_num);
	str_index = 0;
	word = get_first_word_by_space(line, &str_index);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_vector3d(&cone->top, word);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_string_to_double(&cone->height, word, 300.0);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_vector3d(&cone->direction_vec, word);
	cone->direction_vec = normalize_vector3d(cone->direction_vec);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_csv_to_rgb(&cone->color, word);
	free(word);
	word = get_first_word_by_space(line, &str_index);
	convert_string_to_double(&cone->phi, word, 1000.0);
	free(word);
	scene->objects[scene->objects_num] = create_object(
			(void *)cone,
			hit_cone,
			get_normal_vector_for_cone,
			get_pixel_color_for_cone);
	scene->objects_num++;
}
