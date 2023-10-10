/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 22:29:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

/**
 * ファイルの1行から識別子を取得する
*/
t_identifier_type	get_identifier_type(
	const char *const line,
	size_t *index,
	const t_parser parser)
{
	const char	*first_word = get_first_word(line, index);
	size_t		i;

	i = 0;
	while (i < IDENTIFIER_NUM)
	{
		if (is_string_match(first_word, parser.identifier_type_str[i]))
		{
			free(first_word);
			return (i);
		}
		i++;
	}
	free(first_word);
	return (UNDEFINED);
}
