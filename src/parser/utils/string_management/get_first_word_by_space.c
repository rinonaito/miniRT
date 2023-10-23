/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_word_by_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:34:39 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 18:46:23 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "x_wrapper.h"

char	*get_first_word_by_space(const char *const str, size_t *index)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = 0;
	skip_spaces(&start, str);
	*index += start;
	skip_next_space(&len, str + start);
	*index += len;
	return (ft_xsubstr(str, start, len));
}

// int main(void){
//     // Your code here!
//     size_t index = 0;
//     char *str = "1    aaa　　　　  bbb   ccc ddd\n";

//     printf("str = /%s/, all = |%s|\n",
//		get_first_word_by_space(str, &index), str);
//     printf("index = %zu\n", index);
//     printf("str = /%s/, all = |%s|\n",
// 		get_first_word_by_space(str + index, &index), str + index);
//     printf("index = %zu\n", index);
//     printf("str = /%s/, all = |%s|\n",
// 		get_first_word_by_space(str + index, &index), str + index);
//     printf("index = %zu\n", index);
//     printf("str = /%s/, all = |%s|\n",
// 		get_first_word_by_space(str + index, &index), str + index);
//     printf("index = %zu\n", index);
//     printf("str = /%s/, all = |%s|\n",
// 		get_first_word_by_space(str + index, &index), str + index);
//     printf("index = %zu\n", index);
// }
