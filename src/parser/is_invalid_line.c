/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 14:36:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "error_utils.h"
#include "config.h"
#include "common.h"
#include "x_wrapper.h"
#include "libft.h"
#include <stdbool.h>

void _print_invalid_identifier(const t_identifier_type type, const t_parser *parser)
{
	print_error_msg(INVALID_IDENTIFIER);
	ft_xputstr_fd("The invalid identifier is ", STDERR_FILENO);
	ft_xputstr_fd(parser[type].identifier_type_str, STDERR_FILENO);
	ft_xputendl_fd(".", STDERR_FILENO);
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
		free_scene(scene);
		print_error_msg(INVALID_IDENTIFIER_TYPE);
		return (true);
	}
	if (parser[identifier_type].fp_set_identifier(scene, line + index))
	{
		//エラーメッセージをTYPEに合わせて適切にする
		_print_invalid_identifier(identifier_type, parser);
		free_scene(scene);
		return (true);
	}
	return (false);
}
