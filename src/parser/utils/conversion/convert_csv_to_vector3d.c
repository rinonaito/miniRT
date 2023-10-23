/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_csv_to_vector3d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:10:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 14:20:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include <stdlib.h>

//10,-20,5
void	convert_csv_to_vector3d(t_vector3d *vector3d, char *str)
{
	size_t	index;
	char	*word;

	index = 0;
	word = get_first_word_by_comma(str + index, &index);
	convert_string_to_double(&vector3d->x, word, 1000);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	convert_string_to_double(&vector3d->y, word, 1000);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	convert_string_to_double(&vector3d->z, word, 1000);
	free(word);
}
