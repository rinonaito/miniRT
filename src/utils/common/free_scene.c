/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:15:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/29 21:11:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdlib.h>

//TODO:scene->bump_mapをfreeする
void	free_scene(t_scene *scene)
{
	if (scene->lights_num != 0)
		free(scene->lights);
	if (scene->objects_num != 0)
		free(scene->objects);
}
