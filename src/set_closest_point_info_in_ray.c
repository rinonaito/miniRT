/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_closest_point_info_in_ray.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:41:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 17:42:10 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "mlx_utils.h"
#include "color.h"
#include "vector.h"
#include "calculator.h"
#include "config.h"	
#include "light.h"
#include "init.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * レイとシーン内のオブジェクトとの交差判定を行う
 * 交差が確認できた場合、以下2つの情報をレイ構造体へ格納する
 * ⑴最も近い交差点までの距離
 * ⑵最も近い交差点を持つオブジェクトのインデックス
 */
void	set_closest_point_info_in_ray(
	t_ray *ray,
	const t_scene scene)
{
	size_t	i;
	double	current_hit_distance;

	i = 0;
	while (i < scene.objects_num)
	{
		current_hit_distance
			= scene.objects[i].fp_hit_object(*ray, scene.objects[i].object);
		if (current_hit_distance >= HIT_DISTANCE_MIN
			&& current_hit_distance < ray->hit_distance)
		{
			ray->hit_distance = current_hit_distance;
			ray->hit_object_index = i;
		}
		i++;
	}
}
