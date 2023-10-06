/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_2d.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:32 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 15:56:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_vector3d	get_normal_vector_for_2d(
	const t_ray ray,
	const double hit_distance,
	const t_vector3d object_center,
	const t_vector3d object_direction)
{
	(void)ray;
	(void)hit_distance;
	(void)object_center;
	return (object_direction);
}