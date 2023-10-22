/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:11:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:04:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "init.h"

//C -50.0,0,20 0,0,1 70
void	set_camera(t_scene *scene, const char *const line)
{
	size_t	index;
	char	*word;

	index = 0;
	word = get_first_word_by_space(line, &index);
	free(word);
	word = get_first_word_by_space(line, &index);
	convert_csv_to_vector3d(&scene->camera.origin, word);
	free(word);
	word = get_first_word_by_space(line, &index);
	convert_csv_to_vector3d(&scene->camera.direction_vec, word);
	free(word);
	word = get_first_word_by_space(line, &index);
	convert_string_to_double(&scene->camera.fov, word, 180);
	free(word);
}
