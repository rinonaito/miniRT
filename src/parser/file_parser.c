/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:06 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/14 17:17:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static void	_init_parser(t_parser **parser)
{
	*parser = (t_parser *)ft_xcalloc(IDENTIFIER_NUM, sizeof(t_parser));
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

int	file_parser(t_scene *scene, int argc, char **argv)
{
	char		*line;
	t_parser	*parser;
	int			fd;

	if (is_invalid_argc(argc)
		|| is_invalid_file_extension(argv[1]))
		return (EXIT_FAILURE);
	_init_parser(&parser);
	fd = open(argv[FILE_NAME_NUM], O_RDONLY);
	if (fd < 0)
	{
		print_error_msg(FILE_NOT_FOUND);
		return (true);
	}
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
			break ;
		if (is_invalid_line(line, parser, scene))
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
