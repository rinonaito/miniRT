/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/13 19:49:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "libft.h"
#include <stdbool.h>

/**
 * lineにNULLが来ることはない
*/
//TODO:
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
bool	is_invalid_line(
	const char *const line,
	const t_parser *parser,
	t_scene *scene)
{
	t_identifier_type	identifier_type;
	size_t				index;

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
