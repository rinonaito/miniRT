/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 22:24:12 by yshimoma         ###   ########.fr       */
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
	(*parser)[L].fp_is_invalid_identifier = is_invalid_light;
	(*parser)[sp].fp_is_invalid_identifier = is_invalid_sphere;
	(*parser)[pl].fp_is_invalid_identifier = is_invalid_plane;
	(*parser)[cy].fp_is_invalid_identifier = is_invalid_cylinder;
	(*parser)[A].fp_set_identifier = set_ambient;
	(*parser)[C].fp_set_identifier = set_camera;
	(*parser)[L].fp_set_identifier = set_light;
	(*parser)[sp].fp_set_identifier = set_sphere;
	(*parser)[pl].fp_set_identifier = set_plane;
	(*parser)[cy].fp_set_identifier = set_cylinder;
	(*parser)[A].identifier_type_str = AMBIENT;
	(*parser)[C].identifier_type_str = CAMERA;
	(*parser)[L].identifier_type_str = LIGHT;
	(*parser)[sp].identifier_type_str = SPHERE;
	(*parser)[pl].identifier_type_str = PLANE;
	(*parser)[cy].identifier_type_str = CYLINDER;
}

/**
 * lineにNULLが来ることはない
*/
//TODO:
//  fp_is_invalid_identifierで数値かどうか判定する。
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
bool	is_invalid_line(const char *const line, t_scene *scene)
{
	t_parser			*parser;
	t_identifier_type	identifier_type;
	size_t				index;

	_init_parser(&parser);
	if (ft_strlen(line) == 0)
		return (false);
	index = 0;
	identifier_type = get_identifier_type(line, &index, *parser);
	if (identifier_type == UNDEFINED)
	{
		print_error_msg(INVALID_IDENTIFIER);
		return (true);
	}
	//1行の識別子情報までわかっている。
	if (parser[identifier_type].fp_is_invalid_identifier(line, scene, index))
		return (true);
	parser[identifier_type].fp_set_identifier(scene, line);
	return (false);
}
