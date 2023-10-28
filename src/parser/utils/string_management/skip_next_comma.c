/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_next_comma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:49:47 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 19:35:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 次のスペースまでindexを進める関数
*/
void	skip_next_comma(size_t *index, const char *const str)
{
	if (str == NULL)
		return ;
	while (str[*index] != '\0'
		&& str[*index] != ',')
	{
		(*index)++;
	}
}
