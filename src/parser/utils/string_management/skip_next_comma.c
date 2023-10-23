/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_next_comma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:49:47 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 20:28:12 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 次のスペースまでindexを進める関数
*/
void	skip_next_comma(size_t *index, const char *const str)
{
	while (str[*index] != '\0'
		&& str[*index] != '\n'
		&& str[*index] != ',')
	{
		(*index)++;
	}
}
