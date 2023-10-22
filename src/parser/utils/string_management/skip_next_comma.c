/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_next_comma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:49:47 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/11 19:50:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 次のスペースまでindexを進める関数
*/
void	skip_next_comma(size_t *index, const char *const str)
{
	while (str[*index] != '\n'
		&& str[*index] != ',')
	{
		(*index)++;
	}
}
