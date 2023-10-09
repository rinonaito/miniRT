/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:06 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/09 17:28:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int	file_parser(t_scene *scene, int argc, char **argv)
{
	char	*line;
	int		fd;

	if (is_invalid_argc(argc)
		|| is_invalid_file_extension(argv[1]))
		return (EXIT_FAILURE);
	fd = open(argv[FILE_NAME_NUM], O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_invalid_line(line, scene))
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
