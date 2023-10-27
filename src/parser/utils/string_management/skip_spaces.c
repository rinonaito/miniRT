/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:22:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 13:58:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * スペースを飛ばしてインデックス進める関数
*/
void	skip_spaces(size_t *index, const char *const str)
{
	if (str == NULL)
		return ;
	while (str[*index] != '\0'
		&& str[*index] != '\n'
		&& (str[*index] == ' ' || str[*index] == '\t'))
	{
		(*index)++;
	}
}
