/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_csv_to_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:27:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 20:21:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "libft.h"
#include "config.h"
#include <stdlib.h>

//10,0,255
int	convert_csv_to_rgb(t_rgb *rgb, char *str)
{
	size_t	index;
	char	*word;

	if (get_num_of_element_in_token(str) != RGB_NUM)
		return (EXIT_FAILURE);
	index = 0;
	word = get_first_word_by_comma(str + index, &index);
	if (convert_string_to_int(&rgb->red, word) == EXIT_FAILURE)
		return (free(word), EXIT_FAILURE);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	if (convert_string_to_int(&rgb->green, word) == EXIT_FAILURE)
		return (free(word), EXIT_FAILURE);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	if (convert_string_to_int(&rgb->blue, word) == EXIT_FAILURE)
		return (free(word), EXIT_FAILURE);
	free(word);
	return (EXIT_SUCCESS);
}
