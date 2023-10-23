/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_csv_to_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:27:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 14:20:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include "libft.h"
#include <stdlib.h>

//10,0,255
void	convert_csv_to_rgb(t_rgb *rgb, char *str)
{
	size_t	index;
	char	*word;

	index = 0;
	word = get_first_word_by_comma(str + index, &index);
	rgb->red = ft_atoi(word);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	rgb->green = ft_atoi(word);
	free(word);
	word = get_first_word_by_comma(str + index, &index);
	rgb->blue = ft_atoi(word);
	free(word);
}
