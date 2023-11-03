/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_word_by_comma.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:57:04 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:58:33 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "x_wrapper.h"

//19, 255, 0
char	*get_first_word_by_comma(const char *const str, size_t *index)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = 0;
	skip_comma(&start, str);
	*index += start;
	skip_next_comma(&len, str + start);
	*index += len;
	return (ft_xsubstr(str, start, len));
}
