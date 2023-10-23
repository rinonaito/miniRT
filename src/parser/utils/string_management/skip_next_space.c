/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_next_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:42:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 19:55:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 次のスペースまでindexを進める関数
*/
void	skip_next_space(size_t *index, const char *const str)
{
	while (str[*index] != '\n'
		&& str[*index] != ' '
		&& str[*index] != '\t')
	{
		(*index)++;
	}
}
