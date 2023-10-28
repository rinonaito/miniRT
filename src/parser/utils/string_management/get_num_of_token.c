/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:20:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:39:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

//   	pl 0,-1,0   0,1,0.1      255,255,255
//上記で4を返す
size_t	get_num_of_token(const char *line)
{
	size_t	num_of_token;
	size_t	i;

	num_of_token = 0;
	i = 0;
	skip_spaces(&i, line);
	while (line[i] != '\0')
	{
		skip_next_space(&i, line);
		num_of_token++;
		skip_spaces(&i, line);
	}
	return (num_of_token);
}
