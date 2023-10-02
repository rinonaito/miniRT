/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_plane.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:01:19 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 01:19:28 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_vector3d	get_normal_vector_for_plane(
	const t_ray ray,
	const double hit_distance,
	const void *object)
{
	t_plane	*plane;

	(void)ray;
	(void)hit_distance;
	plane = (t_plane *)object;
	return (plane->direction_vec);
}
