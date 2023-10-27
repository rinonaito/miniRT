/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:06 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 11:43:34 by yshimoma         ###   ########.fr       */
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
}

//TODO:closeの失敗でexitするようにラッパー関数を作成する
int	file_parser(t_scene *scene, int argc, char **argv)
{
	char		*line;
	t_parser	*parser;
	int			fd;

	scene->lights_num = 0;
	scene->objects_num = 0;
	if (is_invalid_argc(argc)
		|| is_invalid_file_extension(argv[1]))
		return (EXIT_FAILURE);
	_init_parser(&parser);
	fd = open(argv[FILE_NAME_NUM], O_RDONLY);
	if (fd < 0)
		return (print_error_msg(FILE_NOT_FOUND), true);
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
			break ;
		if (is_invalid_line(line, parser, scene))
			return (free(line), close(fd), EXIT_FAILURE);
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
