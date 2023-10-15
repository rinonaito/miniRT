/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/17 22:21:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdlib.h>

//L -40.0,50.0,0.0 0.6 10,0,255
void	set_light(t_scene *scene, const char *const line)
{
	size_t	str_index;
	char	*word;
	size_t	count;

	//TODO:数分マロックをし直す。
	//	再代入が必要、再代入後にfreeする
	if (scene->lights_num != 0)
		free(scene->lights);
	scene->lights_num++;
	count = 0;
	while (count < scene->lights_num)
	{
	
		count++;
	}
	
	str_index = 0;
	word = get_first_word_by_space(line, &str_index);
	free(word);
	word = get_first_word_by_space(line, &str_index);
}
