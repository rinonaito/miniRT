/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 12:44:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "error_utils.h"
#include "config.h"
#include "libft.h"
#include <stdbool.h>

static void	_free_scene(t_scene *scene)
{
	if (scene->lights_num != 0)
		free(scene->lights);
	if (scene->objects_num != 0)
		free(scene->objects);
}

/**
 * lineにNULLが来ることはない
*/
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
	identifier_type = get_identifier_type(line, &index, parser);
	if (identifier_type == UNDEFINED)
	{
		_free_scene(scene);
		print_error_msg(INVALID_IDENTIFIER_TYPE);
		return (true);
	}
	if (parser[identifier_type].fp_set_identifier(scene, line + index))
	{
		print_error_msg(INVALID_IDENTIFIER);
		_free_scene(scene);
		return (true);
	}
	return (false);
}
