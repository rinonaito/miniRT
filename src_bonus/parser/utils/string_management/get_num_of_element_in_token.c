/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_element_in_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:03:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:20:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

//  255,255,255
//上記で3を返す
size_t	get_num_of_element_in_token(const char *token)
{
	size_t	num_of_element;
	size_t	i;

	num_of_element = 0;
	i = 0;
	skip_spaces(&i, token);
	skip_comma(&i, token);
	while (token[i] != '\0')
	{
		skip_next_comma(&i, token);
		num_of_element++;
		skip_comma(&i, token);
		skip_spaces(&i, token);
	}
	return (num_of_element);
}
