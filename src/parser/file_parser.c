/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:06 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:12:40 by rnaito           ###   ########.fr       */
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

//TODO:
//	バンプマップファイルはあってもなくても良いが、ファイルが2つある場合は、エラーチェックをする
int	file_parser(t_scene *scene, int argc, char **argv)
{
	bool	have_bump_texture;
	bool	have_bump_map;

	scene->lights_num = 0;
	scene->objects_num = 0;
	have_bump_texture = false;
	have_bump_map = false;
	if (is_invalid_argc(argc) || is_invalid_file_extension(argv[1]))
		return (EXIT_FAILURE);
	if (rt_parser(argv[1], scene, &have_bump_texture) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (argc == VALID_ARGC_NUM + BONUS_ARGS)
	{
		if (ppm_parser(argv[2], scene) == EXIT_FAILURE)
		{
			print_error_msg(INVALID_PPM_FILE);
			return (EXIT_FAILURE);
		}
		have_bump_map = true;
	}
	if (have_bump_texture && !have_bump_map)
		return (print_error_msg(LACK_OF_PPM), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
