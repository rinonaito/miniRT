/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:06 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 15:43:12 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include "config.h"
#include "x_wrapper.h"
#include "init.h"
#include "error_utils.h"
#include "common.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

//高さと幅を格納する関数
static int	_set_map_size(const int fd, t_bumpmap *bump_map)
{
	char	*line;
	size_t	index;
	bool	is_error;
	char	*word;

	is_error = false;
	line = get_next_line_no_nl(fd);
	if (line == NULL)
		return (EXIT_FAILURE);
	if (get_num_of_token(line) != 2)
		is_error = true;
	index = 0;
	word = get_first_word_by_space(line, &index);
	if (is_error
		|| convert_string_to_int(&bump_map->map_width, word) == EXIT_FAILURE)
		is_error = true;
	free (word);
	word = get_first_word_by_space(line + index, &index);
	if (is_error
		|| convert_string_to_int(&bump_map->map_height, word) == EXIT_FAILURE)
		is_error = true;
	free (word);
	free(line);
	return (is_error);
}

//max_color = 最大からーの格納関数
static int	_set_max_color(const int fd, int *max_color)
{
	char	*line;
	size_t	index;
	bool	is_error;
	char	*word;

	is_error = false;
	line = get_next_line_no_nl(fd);
	if (line == NULL)
		return (EXIT_FAILURE);
	if (get_num_of_token(line) != 1)
		is_error = true;
	index = 0;
	word = get_first_word_by_space(line, &index);
	free(line);
	if (is_error
		|| convert_string_to_int(max_color, word) == EXIT_FAILURE)
		is_error = true;
	free(word);
	if (is_error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//ファイル１行目のエラー処理
static bool	_is_invalid_header(const int fd)
{
	char	*line;

	line = get_next_line_no_nl(fd);
	if (line == NULL)
		return (false);
	if (ft_strlen(line) != 2
		|| (line[0] != 'P' && line[1] != '3'))
		return (true);
	free(line);
	return (false);
}

static int	_read_map_from_ppm_file(
	const int fd,
	t_bumpmap *bump_map,
	const int max_color)
{
	char	*line;
	int		count_map_height;

	malloc_2dimensional_array((void ***)&bump_map->map,
		sizeof(t_bumpmap *) * bump_map->map_height,
		sizeof(t_bumpmap) * bump_map->map_width,
		bump_map->map_height);
	count_map_height = 0;
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
			break ;
		if (set_normal_bump_in_bump_map(
				line, bump_map, max_color, count_map_height) == EXIT_FAILURE)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
		count_map_height++;
	}
	if (count_map_height != bump_map->map_height)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ppm_parser(const char *filename, t_scene *scene)
{
	int		fd;
	int		max_color;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (_is_invalid_header(fd)
		|| _set_map_size(fd, &scene->bump_map) == EXIT_FAILURE
		|| _set_max_color(fd, &max_color) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (_read_map_from_ppm_file(fd, &scene->bump_map, max_color)
		== EXIT_FAILURE)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
