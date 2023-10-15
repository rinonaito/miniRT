/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector3d_from_csv.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:10:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/15 17:11:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "types.h"
#include <stdlib.h>

//10,-20,5
void	parse_vector3d_from_csv(t_vector3d *vector3d, char *str)
{
	size_t	index;
	char	*word;

	index = 0;
	word = get_first_word_by_comma(str, &index);
	vector3d->x = ft_atoi(word);
	free(word);
	word = get_first_word_by_comma(str, &index);
	vector3d->y = ft_atoi(word);
	free(word);
	word = get_first_word_by_comma(str, &index);
	vector3d->z = ft_atoi(word);
	free(word);
}
