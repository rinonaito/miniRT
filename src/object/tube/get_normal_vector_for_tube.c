/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_tube.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naitorino <naitorino@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:17 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 19:59:23 by naitorino        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

t_vector3d	get_normal_vector_for_tube(
	const t_ray ray,
	const double hit_distance,
	const void *object)
{
	t_tube	*tube;

	tube = (t_tube *)object;
	return (get_normal_vector_for_3d(ray, hit_distance, tube->center));
}
