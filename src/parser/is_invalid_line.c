/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 13:39:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "error_utils.h"
#include "config.h"
#include "libft.h"
#include <stdbool.h>

void	_print_identifier(t_scene *scene, t_identifier_type identifier_type)
{
	if (identifier_type = A)
	{

	}
	else if (identifier_type = C)
	{

	}
	else if (identifier_type = L)
	{

	}
	else if (identifier_type = sp)
	{

	}
	else if (identifier_type = pl)
	{

	}
	else if (identifier_type = cy)
	{

	}
	else if (identifier_type = co)
	{

	}
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
		print_error_msg(INVALID_IDENTIFIER);
		return (true);
	}
	//1行の識別子情報までわかっている。
	// if (parser[identifier_type].fp_is_invalid_identifier(line, scene, index))
	// 	return (true);
	parser[identifier_type].fp_set_identifier(scene, line);
	_print_identifier(scene, identifier_type);
	return (false);
}
