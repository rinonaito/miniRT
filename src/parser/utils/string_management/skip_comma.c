/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_comma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:48:28 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 13:59:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * カンマを飛ばしてインデックス進める関数
*/
void	skip_comma(size_t *index, const char *const str)
{
	if (str == NULL)
		return ;
	while (str[*index] != '\0'
		&& str[*index] != '\n'
		&& str[*index] == ',')
	{
		(*index)++;
	}
}
