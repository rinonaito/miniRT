/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_bump_in_bump_map.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:54:41 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/29 21:05:40 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "error_utils.h"
#include "config.h"
#include "common.h"
#include "x_wrapper.h"
#include "libft.h"
#include "vector.h"
#include <stdbool.h>

static int	_set_normal_bump(
	t_vector3d *normal_bump,
	const char *line,
	size_t *str_index,
	const int max_color)
{
	if (convert_string_to_double(&normal_bump->x,
			get_first_word_by_space(line + *str_index, str_index), max_color)
		== EXIT_FAILURE
		|| is_invalid_int(normal_bump->x, max_color, MIN_COLOR_RANGE)
		|| convert_string_to_double(&normal_bump->y,
			get_first_word_by_space(line + *str_index, str_index), max_color)
		== EXIT_FAILURE
		|| is_invalid_int(normal_bump->y, max_color, MIN_COLOR_RANGE)
		|| convert_string_to_double(&normal_bump->z,
			get_first_word_by_space(line + *str_index, str_index), max_color)
		== EXIT_FAILURE
		|| is_invalid_int(normal_bump->z, max_color, MIN_COLOR_RANGE))
	{
		return (EXIT_FAILURE);
	}
	*normal_bump = normalize_vector3d(*normal_bump);
	return (EXIT_SUCCESS);
}

/**
 * lineにNULLが来ることはない
*/
int	set_normal_bump_in_bump_map(
	const char *const line,
	t_bumpmap *bump_map,
	const int max_color,
	int count_map_height)
{
	size_t	str_index;
	int		i;

	if (count_map_height > bump_map->map_height
		|| get_num_of_token(line) != (size_t)bump_map->map_width * RGB_NUM)
		return (EXIT_FAILURE);
	str_index = 0;
	i = 0;
	while (i < bump_map->map_width)
	{
		if (_set_normal_bump(&(bump_map->map[count_map_height][i]),
			line, &str_index, max_color)
			== EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
