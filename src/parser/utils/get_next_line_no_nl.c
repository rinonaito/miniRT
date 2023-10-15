/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_no_nl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:08:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/13 20:12:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * 改行を削除したget_next_line
*/
char	*get_next_line_no_nl(int fd)
{
	char	*line_no_nl;
	size_t	len;

	line_no_nl = get_next_line(fd);
	if (line_no_nl == NULL)
		return (NULL);
	len = ft_strlen(line_no_nl);
	if (len > 0 && line_no_nl[len - 1] == '\n')
		line_no_nl[len - 1] = '\0';
	return (line_no_nl);
}
