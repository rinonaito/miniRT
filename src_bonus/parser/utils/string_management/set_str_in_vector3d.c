/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_in_vector3d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:54:39 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/27 12:22:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parser.h"

//機能：
//	①第二引数を第一引数のデータ型に合わせて変換する
//	②変換したデータを第一引数へ格納
//	③indexを進める
//	④不要データのメモリ解放
int	set_str_in_vector3d(
		t_vector3d *vector3d,
		const char *line,
		size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	if (convert_csv_to_vector3d(vector3d, word) == EXIT_FAILURE)
	{
		free(word);
		return (EXIT_FAILURE);
	}
	free(word);
	return (EXIT_SUCCESS);
}
