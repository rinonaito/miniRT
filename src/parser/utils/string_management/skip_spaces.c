/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:22:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 19:45:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * スペースを飛ばしてインデックス進める関数
*/
void	skip_spaces(size_t *index, const char *const str)
{
	while (str[*index] != '\n'
		&& (str[*index] == ' ' || str[*index] == '\t'))
	{
		(*index)++;
	}
}
