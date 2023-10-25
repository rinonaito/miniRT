/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/25 22:33:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "error_utils.h"
#include "config.h"
#include "libft.h"
#include <stdbool.h>

// static void	_free_scene(t_scene *scene)
// {
// 	free(scene->lights);
// 	free(scene>-objects);
// }

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
		print_error_msg(INVALID_IDENTIFIER_TYPE);
		// free_scene();
		return (true);
	}
	//TODO:set_identifierに正常終了か以上終了かの戻り値をつける。
	parser[identifier_type].fp_set_identifier(scene, line + index);
	// if (parser[identifier_type].fp_set_identifier(scene, line + index))
	// {
	// 	print_error_msg(INVALID_IDENTIFIER);
	// 	// free_scene();
	// 	return (true);
	// }
	return (false);
}
