/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_in_vector3d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:54:39 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/23 20:21:26 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parser.h"

//機能：
//	①第二引数を第一引数のデータ型に合わせて変換する
//	②変換したデータを第一引数へ格納
//	③indexを進める
//	④不要データのメモリ解放
void	set_str_in_vector3d(
		t_vector3d *vector3d,
		const char *line,
		size_t *index)
{
	char	*word;

	word = get_first_word_by_space(line + (*index), index);
	convert_csv_to_vector3d(vector3d, word);
	free(word);
}
