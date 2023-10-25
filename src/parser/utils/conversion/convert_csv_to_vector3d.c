/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_csv_to_vector3d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:10:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/25 21:55:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include <stdlib.h>

//10,-20,5
int	convert_csv_to_vector3d(t_vector3d *vector3d, char *str)
{
	size_t	index;
	char	*word;

	index = 0;
	word = get_first_word_by_comma(str + index, &index);
	if (convert_string_to_double(&vector3d->x, word, 1000) == EXIT_FAILURE)
		return (free(word), EXIT_FAILURE);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	if (convert_string_to_double(&vector3d->y, word, 1000) == EXIT_FAILURE)
		return (free(word), EXIT_FAILURE);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	if (convert_string_to_double(&vector3d->z, word, 1000) == EXIT_FAILURE)
		return (free(word), EXIT_FAILURE);
	free(word);
	return (EXIT_SUCCESS);
}
