/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/09 18:24:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "libft.h"
#include <stdbool.h>

static void	_init_parser(t_parser **parser)
{
	*parser = (t_parser *)ft_xcalloc(6, sizeof(t_parser));
	(*parser)[A].fp_is_invalid_identifier = is_invalid_ambient;
	(*parser)[C].fp_is_invalid_identifier = is_invalid_camera;
	(*parser)[L].fp_is_invalid_identifier = is_invalid_cylinder;
	(*parser)[sp].fp_is_invalid_identifier = is_invalid_light;
	(*parser)[pl].fp_is_invalid_identifier = is_invalid_plane;
	(*parser)[cy].fp_is_invalid_identifier = is_invalid_sphere;
	(*parser)[A].fp_set_identifier = set_ambient;
	(*parser)[C].fp_set_identifier = set_camera;
	(*parser)[L].fp_set_identifier = set_cylinder;
	(*parser)[sp].fp_set_identifier = set_light;
	(*parser)[pl].fp_set_identifier = set_plane;
	(*parser)[cy].fp_set_identifier = set_sphere;
}

/**
 * lineにNULLが来ることはない
*/
//TODO:get_identifier_typeの実装から
//・is_invalid_ambient
//・is_invalid_camera
//・is_invalid_cylinder
//・is_invalid_light
//・is_invalid_plane
//・is_invalid_sphere
//・set_ambient
//・set_camera
//・set_cylinder
//・set_light
//・set_plane
//・set_sphere
//・is_invalid_double_ratio
//・is_invalid_int_ratio
//・is_invalid_coordinates_ratio
//・is_invalid_fov_ratio
//・is_invalid_lighting_ratio
//・is_invalid_normalized_vector_ratio
//・is_invalid_rgb_ratio
//・skip_spaces
bool	is_invalid_line(const char *const line, t_scene *scene)
{
	t_parser		*parser;
	t_identifier	identifier_type;
	size_t			index;

	_init_parser(&parser);
	if (ft_strlen(line) == 0)
		return (false);
	index = 0;
	identifier_type = get_identifier_type(line, &index);
	if (identifier_type == UNDEFINED)
		return (true);
	if (parser[identifier_type].fp_is_invalid_identifier(line, scene, index))
		return (true);
	parser[identifier_type].fp_set_identifier(scene, line);
	return (false);
}
