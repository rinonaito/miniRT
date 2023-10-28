/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:06 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:37:31 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include "config.h"
#include "x_wrapper.h"
#include "init.h"
#include "error_utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static bool	_is_invalid_num_of_definitions(t_parser *parser)
{
	if (parser[A].num_of_lines != 1
		|| parser[C].num_of_lines != 1
		|| parser[L].num_of_lines < 1)
		return (true);
	return (false);
}

static void	_init_parser(t_parser **parser)
{
	*parser = (t_parser *)ft_xcalloc(IDENTIFIER_NUM, sizeof(t_parser));
	(*parser)[A].fp_set_identifier = set_ambient;
	(*parser)[C].fp_set_identifier = set_camera;
	(*parser)[L].fp_set_identifier = set_light;
	(*parser)[sp].fp_set_identifier = set_sphere;
	(*parser)[pl].fp_set_identifier = set_plane;
	(*parser)[cy].fp_set_identifier = set_cylinder;
	(*parser)[co].fp_set_identifier = set_cone;
	(*parser)[A].identifier_type_str = AMBIENT;
	(*parser)[C].identifier_type_str = CAMERA;
	(*parser)[L].identifier_type_str = LIGHT;
	(*parser)[sp].identifier_type_str = SPHERE;
	(*parser)[pl].identifier_type_str = PLANE;
	(*parser)[cy].identifier_type_str = CYLINDER;
	(*parser)[co].identifier_type_str = CONE;
	(*parser)[A].num_of_lines = 0;
	(*parser)[C].num_of_lines = 0;
	(*parser)[L].num_of_lines = 0;
	(*parser)[sp].num_of_lines = 0;
	(*parser)[pl].num_of_lines = 0;
	(*parser)[cy].num_of_lines = 0;
	(*parser)[co].num_of_lines = 0;
}

//TODO:closeの失敗でexitするようにラッパー関数を作成する
static int	_rt_parser(const char *filename, t_parser *parser, t_scene *scene)
{
	char		*line;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error_msg(FILE_NOT_FOUND);
		return (EXIT_FAILURE);
	}
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
			break ;
		if (set_line_info_in_scene(line, parser, scene) == EXIT_FAILURE)
		{
			free(line);
			close(fd);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	file_parser(t_scene *scene, int argc, char **argv)
{
	t_parser	*parser;

	scene->lights_num = 0;
	scene->objects_num = 0;
	if (is_invalid_argc(argc)
		|| is_invalid_file_extension(argv[1]))
		return (EXIT_FAILURE);
	_init_parser(&parser);
	if (_rt_parser(argv[1], parser, scene) == EXIT_FAILURE
		|| _is_invalid_num_of_definitions(parser))
	{
		free(parser);
		return (EXIT_FAILURE);
	}
	free(parser);
	return (EXIT_SUCCESS);
}
