/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_line_info_in_scene.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:15:14 by rnaito           ###   ########.fr       */
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

void	_print_invalid_identifier(
	const t_identifier_type type,
	const t_parser *parser)
{
	print_error_msg(INVALID_IDENTIFIER1);
	ft_xputstr_fd(INVALID_IDENTIFIER2, STDERR_FILENO);
	ft_xputstr_fd(parser[type].identifier_type_str, STDERR_FILENO);
	ft_xputendl_fd(".", STDERR_FILENO);
}

/**
 * lineにNULLが来ることはない
*/
int	set_line_info_in_scene(
	const char *const line,
	t_parser *parser,
	t_scene *scene,
	bool *have_bump_texture)
{
	t_identifier_type	identifier_type;
	size_t				index;

	if (ft_strlen(line) == 0)
		return (EXIT_SUCCESS);
	index = 0;
	identifier_type = get_identifier_type(line, &index, parser);
	if (identifier_type == UNDEFINED)
	{
		free_scene(scene);
		print_error_msg(INVALID_IDENTIFIER_TYPE);
		return (EXIT_FAILURE);
	}
	parser[identifier_type].num_of_lines++;
	if (parser[identifier_type].fp_set_identifier(
			scene, line + index, have_bump_texture) == EXIT_FAILURE)
	{
		_print_invalid_identifier(identifier_type, parser);
		free_scene(scene);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
