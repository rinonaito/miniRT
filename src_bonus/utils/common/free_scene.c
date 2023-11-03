/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:15:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:46:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdlib.h>

void	free_scene(t_scene *scene)
{
	if (scene->lights_num != 0)
		free(scene->lights);
	if (scene->objects_num != 0)
		free(scene->objects);
}
