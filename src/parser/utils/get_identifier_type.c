/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 20:50:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

/**
 * ファイルの1行から識別子を取得する
*/
t_identifier	get_identifier_type(const char *const line, size_t *index)
{
	const char	*first_word = get_first_word(line, index);

	//TODO:
	//以下から開始。
	//文字列を取れたため、判定。
}