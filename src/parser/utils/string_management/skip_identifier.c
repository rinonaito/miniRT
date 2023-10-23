/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:57:54 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/23 20:16:29 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"

void	skip_identifier(const char *line, size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	free(word);
}
