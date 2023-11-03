/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_in_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:54:35 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/27 12:22:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include <unistd.h>

int	set_str_in_rgb(
		t_rgb *rgb,
		const char *line,
		size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	if (convert_csv_to_rgb(rgb, word) == EXIT_FAILURE)
	{
		free(word);
		return (EXIT_FAILURE);
	}
	free(word);
	return (EXIT_SUCCESS);
}
