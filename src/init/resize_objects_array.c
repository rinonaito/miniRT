/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_objects_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:40:56 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 13:14:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "x_wrapper.h"

void	resize_objects_array(t_object **objects, const size_t objects_num)
{
	t_object	*backup;
	size_t		i;

	backup = *objects;
	*objects = ft_xcalloc(objects_num + 1, sizeof(t_object));
	i = 0;
	while (i < objects_num)
	{
		(*objects)[i] = backup[i];
		i++;
	}
	if (objects_num != 0)
		free(backup);
}
