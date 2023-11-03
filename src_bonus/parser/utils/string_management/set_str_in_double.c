/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_in_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:54:42 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/27 12:21:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>

int	set_str_in_double(
		double *num,
		const char *line,
		size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	if (convert_string_to_double(num, word, 1000.0) == EXIT_FAILURE)
	{
		free(word);
		return (EXIT_FAILURE);
	}
	free(word);
	return (EXIT_SUCCESS);
}
