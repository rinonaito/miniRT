/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:11:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:54:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "parser.h"

//A 0.2 255,255,255
//TODO
//作成した方が良い関数
//	数値変換
//	get_first_word_by_spaceを'\0'まで使えば簡単にできる。
//	
void	set_ambient(t_scene *scene, const char *const line)
{
	size_t	index;
	char	*word;

	index = 0;
	word = get_first_word_by_space(line, &index);
	free(word);
	word = get_first_word_by_space(line, &index);
	convert_string_to_double(&scene->ambient.lighting_ratio, word, 300.0);
	free(word);
	word = get_first_word_by_space(line, &index);
	convert_csv_to_rgb(&scene->ambient.color, word);
	free(word);
}
