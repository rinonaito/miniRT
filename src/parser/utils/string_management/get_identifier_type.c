/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 18:16:43 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdlib.h>

/**
 * ファイルの1行から識別子を取得する
*/
t_identifier_type	get_identifier_type(
	const char *const line,
	size_t *index,
	const t_parser *parser)
{
	char	*first_word;
	size_t	i;

	first_word = get_first_word_by_space(line, index);
	i = 0;
	while (i < IDENTIFIER_NUM)
	{
		if (is_string_match(first_word, parser[i].identifier_type_str))
		{
			free(first_word);
			return (i);
		}
		i++;
	}
	free(first_word);
	return (UNDEFINED);
}
