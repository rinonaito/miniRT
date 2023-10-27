/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:11:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 11:52:22 by yshimoma         ###   ########.fr       */
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
int	set_ambient(t_scene *scene, const char *const line)
{
	size_t	str_index;

	str_index = 0;
	if (set_str_in_double(&scene->ambient.lighting_ratio, line, &str_index)
		== EXIT_FAILURE
		|| set_str_in_rgb(&scene->ambient.color, line, &str_index)
		== EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
