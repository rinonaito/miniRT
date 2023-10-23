/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_in_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:54:42 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/23 20:17:18 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>

void	set_str_in_double(
		double *num,
		const char *line,
		size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	convert_string_to_double(num, word, 1000.0);
	free(word);
}
