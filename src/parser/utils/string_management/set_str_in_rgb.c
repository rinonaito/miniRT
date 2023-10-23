/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_in_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:54:35 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/23 20:29:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"
#include <unistd.h>

void	set_str_in_rgb(
		t_rgb *rgb,
		const char *line,
		size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	convert_csv_to_rgb(rgb, word);
	free(word);
}
