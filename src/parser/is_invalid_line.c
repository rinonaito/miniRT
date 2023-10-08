/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:44:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/08 12:47:05 by yshimoma         ###   ########.fr       */
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

bool	is_invalid_line(char *line, t_scene *scene)
{
	t_parser		*parser;
	t_identifier	identifier_type;
	size_t			index;

	_init_parser(&parser);
	if (line == NULL || ft_strlen(line) == 0)
		return (true);
	index = 0;
	identifier_type = get_identifier_type(line, &index);
	if (identifier_type == UNDEFINED)
		return (true);
	if (parser[identifier_type].fp_is_invalid_identifier(line, scene, index))
		return (true);
	parser[identifier_type].fp_set_identifier(scene, line);
	return (false);
}
